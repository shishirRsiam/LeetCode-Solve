class Solution {
    public:
        int countNode = 0;
        vector<bool> visited;
        vector<vector<int>> adj;
        unordered_map<int, int> store;
        void dfs(int node)
        {
            countNode += 1;
            visited[node] = true;
            store[node] = adj[node].size();
            
            for(auto &child : adj[node])
                if(not visited[child]) dfs(child);
        }
        int countCompleteComponents(int n, vector<vector<int>>& edges) 
        {
            adj.resize(n);
            visited.resize(n);
            for(auto &ed : edges)
            {
                adj[ed[0]].push_back(ed[1]);
                adj[ed[1]].push_back(ed[0]);
            }
    
            int ans = 0;
            for(int i = 0; i < n; i++)
            {
                if(not visited[i])
                {
                    dfs(i);
    
                    bool isConnected = true;
                    for(auto [node, count] : store)
                        if(count + 1 != countNode) isConnected = false;
    
                    store.clear();
                    countNode = 0;
                    ans += isConnected;
                }
            }
    
            return ans;
        }
    };