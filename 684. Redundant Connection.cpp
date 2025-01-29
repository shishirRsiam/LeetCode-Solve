class Solution {
public:
    void dfs(int node, int &count, vector<unordered_set<int>>& adj, vector<bool>& visited)
    {
        count += 1;
        visited[node] = true;
        for(auto child : adj[node])
            if(not visited[child]) dfs(child, count, adj, visited);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        int n = edges.size();
        vector<unordered_set<int>> adj(n + 1); 
        for(auto ed : edges)
        {
            adj[ed[0]].insert(ed[1]);
            adj[ed[1]].insert(ed[0]);
        }  

        vector<int> ans = {0, 0}; 
        for(auto ed : edges)
        {
            vector<bool> visited(n);
            int u = ed[0], v = ed[1], count = 0;

            adj[u].erase(v);
            adj[v].erase(u);
            dfs(1, count, adj, visited);
            if(count == n) ans = {u, v};

            adj[u].insert(v);
            adj[v].insert(u);
        }  
        return ans;
    }
};