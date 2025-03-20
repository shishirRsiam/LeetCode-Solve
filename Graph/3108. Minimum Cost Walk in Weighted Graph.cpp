class Solution {
    public:
        int components = 0;
        vector<bool> visited;
        vector<vector<pair<int, int>>> adj;
        vector<int> storeComponents, componentAnd;
        int DFS(int node) 
        {
            int And = INT_MAX; 
            visited[node] = true;
            storeComponents[node] = components;
    
            for (auto [child, cost] : adj[node]) 
            {
                And &= cost;
                if (!visited[child]) And &= DFS(child);
            }
            return And;
        }
        vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) 
        {
            adj.resize(n);
            visited.resize(n);
            componentAnd.resize(n, -1);
            storeComponents.resize(n);
            for(auto &edg : edges)
            {
                int u = edg[0], v = edg[1], c = edg[2];
                adj[u].push_back({v, c});
                adj[v].push_back({u, c});
            }
    
            
            for(int i = 0; i < n; i++)
            {
                if(not visited[i])
                {
                    componentAnd[components] = DFS(i);
                    components += 1;
                }
            }
    
            vector<int> ans;
            for(auto qu : query)
            {
                int And = -1;
                if(storeComponents[qu[0]] == storeComponents[qu[1]])
                    And = componentAnd[storeComponents[qu[0]]];
                ans.push_back(And);
            }
    
            return ans;
        }
    };