class Solution {
public:
    vector<int>path;
    unordered_map<int, vector<int>>adj;
    void DFS(int node)
    {
        while(!adj[node].empty())
        {
            int next = adj[node].back();
            adj[node].pop_back();
            DFS(next);
        }
        path.push_back(node);
    }
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) 
    {
        unordered_map<int, int>indegree, outdegree;
        
        for(auto& pair : pairs)
        {
            int u = pair[0], v = pair[1];

            outdegree[u]++;
            indegree[v]++;
            adj[u].push_back(v);
        }

        int startPath = pairs[0][0];
        for(auto& [node, degree] : outdegree)
        {
            if(outdegree[node] - indegree[node] == 1)
            {
                startPath = node;
                break;
            }
        }

        DFS(startPath);

        int n = path.size();
        vector<vector<int>> ans;
        reverse(begin(path), end(path));
        for(int i = 0; i < n - 1; i++)
            ans.push_back({path[i], path[i + 1]});

        return ans;
    }
};