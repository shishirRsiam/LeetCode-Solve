class Solution {
public:
    void dfsCycle(int node, int &maxLengthCycle, vector<int>& favorite, vector<int>& visited, vector<int>& depth)
    {
        visited[node] = 1;
        int nextNode = favorite[node];
        if(!visited[nextNode])
        {
            depth[nextNode] = depth[node] + 1;
            dfsCycle(nextNode, maxLengthCycle, favorite, visited, depth);
        }
        else if(visited[nextNode] == 1) maxLengthCycle = max(maxLengthCycle, depth[node] - depth[nextNode] + 1);
        visited[node] = 2;
    }
    int dfsMutualChecking(int node, vector<vector<int>>& reverseAdj, vector<int>& favorite)
    {
        int maxNode = 1;
        for(auto neigthbor : reverseAdj[node])
            if(neigthbor != favorite[node])
                maxNode = max(maxNode, dfsMutualChecking(neigthbor, reverseAdj, favorite) + 1);
        return maxNode;
    }
    int maximumInvitations(vector<int>& favorite) 
    {
        int n = favorite.size(), maxLengthCycle = 0, mutualSum = 0;

        vector<int> visited(n), depth(n);
        vector<vector<int>> reverseAdj(n);
        for(int i = 0; i < n; i++)
        {
            int u = i, v = favorite[i];
            reverseAdj[v].push_back(u);
            if(not visited[i]) dfsCycle(i, maxLengthCycle, favorite, visited, depth);
        }
        
        for(int i = 0; i < n; i++)
        {
            if(favorite[favorite[i]] == i and i < favorite[i])
            {
                mutualSum += dfsMutualChecking(i, reverseAdj, favorite) + dfsMutualChecking(favorite[i], reverseAdj, favorite);
            }
        }

        return max(maxLengthCycle, mutualSum);    
    }
};