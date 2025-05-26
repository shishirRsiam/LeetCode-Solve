class Solution {
public:
    string s;
    vector<int> visited;
    bool isCycle = false;
    vector<vector<int>> adj, memo;
    
    void dfs(int &node)
    {
        if(isCycle) return;

        visited[node] = 1;
        for(auto &child : adj[node])
        {
            if(not visited[child])
            {
                dfs(child);
                if (isCycle) return;
            }
            else if(visited[child] == 1) isCycle = true;

            for(int index = 0; index < 26; index++)
                memo[node][index] = max(memo[node][index], memo[child][index]);
        }
        visited[node] = 2;
        memo[node][s[node] - 'a'] += 1;
    }
    int largestPathValue(string colors, vector<vector<int>>& edges) 
    {
        int n = colors.size();

        adj.resize(n);
        visited.resize(n);
        memo.assign(n, vector<int>(26, 0));
        for(auto &ed : edges)
            adj[ed[0]].push_back(ed[1]);

        s = colors;
        for(int node = 0; node < n; node++)
        {
            if(not visited[node]) 
            {
                dfs(node);
                if(isCycle) return -1;
            }
        }

        int ans = 0;
        for(int node = 0; node < n; node++)
            for(int index = 0; index < 26; index++)
                ans = max(ans, memo[node][index]);
        return ans;
    }
};