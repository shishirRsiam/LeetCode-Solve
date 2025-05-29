class Solution {
public:
    vector<int> store;
    unordered_map<int, int> count1, count2;
    void dfs(int node, int flag, unordered_map<int, int>& countMap, vector<int>& visited, vector<vector<int>>& adj) 
    {
        countMap[flag]++;
        store[node] = flag;
        visited[node] = true;
        for (auto& child : adj[node]) 
        {
            if (!visited[child]) 
            {
                dfs(child, not flag, countMap, visited, adj);
            }
        }
    }

    vector<vector<int>> getAdj(const vector<vector<int>>& edges) 
    {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);
        for (auto& edge : edges)
        {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) 
    {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        auto adj1 = getAdj(edges1), adj2 = getAdj(edges2);
        store.resize(max(n, m));

        vector<int> visited1(n, 0), visited2(m, 0);
        dfs(0, 0, count2, visited2, adj2);
        dfs(0, 0, count1, visited1, adj1);

        vector<int> ans(n);  
        for(int i = 0; i < n; i++)
        {
            bool flag = store[i];
            ans[i] = count1[flag] + max(count2[0], count2[1]);
        }
        return ans;
    }
};