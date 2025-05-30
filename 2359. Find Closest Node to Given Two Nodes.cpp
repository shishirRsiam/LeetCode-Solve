class Solution {
public:
    unordered_map<int, int> count;
    void dfs(int node, int cnt, vector<int> &visited, vector<vector<int>> &adj, unordered_map<int, int> &count)
    {
        count[node] += cnt;
        visited[node] = true;
        for(auto &child : adj[node])
            if(not visited[child])
                dfs(child, cnt + 1, visited, adj, count);
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) 
    {
        int n = edges.size();
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++)
        {
            if(edges[i] == -1) continue;
            adj[i].push_back(edges[i]);
        }

        vector<int> visited1(n + 1), visited2(n + 1);
        unordered_map<int, int> count1, count2;

        dfs(node1, 0, visited1, adj, count1);        
        dfs(node2, 0, visited2, adj, count2);

        int ans = -1, minMaxDist = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            if(count1.count(i) and count2.count(i))
            {
                int maxDistance = max(count1[i], count2[i]);
                if(maxDistance < minMaxDist or (maxDistance == minMaxDist and i < ans))
                    ans = i, minMaxDist = maxDistance;
            }
        }
        
        return ans;
    }
};