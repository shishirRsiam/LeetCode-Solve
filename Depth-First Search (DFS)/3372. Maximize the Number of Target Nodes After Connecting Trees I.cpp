class Solution {
public:
    void dfs(int node, int k, int &count, vector<bool> &visited, vector<vector<int>> &adj)
    {
        count += 1;
        if(k <= 0) return;

        visited[node] = true;
        for(auto &child : adj[node])
        {
            if(not visited[child])
            {
                dfs(child, k - 1, count, visited, adj);
            }
        }
    }
    auto getAdj(vector<vector<int>> &edges)
    {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);
        for(int i = 0; i < n; i++)
        {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) 
    {
        auto adj1 = getAdj(edges1), adj2 = getAdj(edges2);

        vector<bool> visited;
        int maxCountNode = 0, count;
        int n = edges1.size(), m = edges2.size();
        for(int i = 0; i <= m; i++)
        {
            if(k == 0) break;
            count = 0;
            visited.assign(m + 1, false);
            dfs(i, k - 1, count, visited, adj2);
            maxCountNode = max(maxCountNode, count);
        }

        vector<int> ans(n + 1);
        for(int i = 0; i <= n; i++)
        {
            count = 0;
            visited.assign(n + 1, false);
            dfs(i, k, count, visited, adj1);
            ans[i] = count + maxCountNode;
        }

        return ans;
    }
};