class Solution {
public:
    int ans = 0;
    unordered_map<int, vector<int>> adj;
    long dfs(int node, int parent, int &k, vector<int>& values)
    {
        long subTreeSum = values[node];
        for(auto &child : adj[node])
        {
            if(child != parent) 
                subTreeSum += dfs(child, node, k, values);
        }

        if(subTreeSum % k == 0) 
            ans += 1, subTreeSum = 0;
        return subTreeSum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) 
    {
        for(auto &ed : edges)
        {
            int u = ed[0], v = ed[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }   
        
        dfs(0, -1, k, values);
        return ans; 
    }
};