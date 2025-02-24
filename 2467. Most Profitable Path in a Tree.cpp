class Solution {
    public:
        int aliceIncome = INT_MIN;
        unordered_map<int, int> bobTime, visited;
    
        unordered_map<int, vector<int>> adj;
        bool dfsForBob(int node, int time)
        {
            visited[node]= true;
            if(node == 0)
            {
                bobTime[node] = time;
                return true;
            }
    
            for(auto child : adj[node])
            {
                if(not visited[child])
                {
                    if(dfsForBob(child, time + 1))
                    {
                        bobTime[node] = time;
                        return true;
                    }
                }
            }
            return false;
        }
        void dfsForAlice(int node, int time, int income, vector<int> &amount)
        {
            visited[node] = true;
    
            if(not bobTime.count(node) or time < bobTime[node])
                income += amount[node];
            else if(time == bobTime[node])
                income += (amount[node] / 2);            
    
            bool isLeaf = true;
            for(auto child : adj[node])
            {
                if(not visited[child])
                {
                    isLeaf = false;
                    dfsForAlice(child, time + 1, income, amount);
                }
            }
            if(isLeaf)
                aliceIncome = max(aliceIncome, income);
        }
        
        int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) 
        {
            for (auto &edge : edges) 
            {
                adj[edge[0]].push_back(edge[1]);
                adj[edge[1]].push_back(edge[0]);
            }
            
            dfsForBob(bob, 0); 
    
            visited.clear();      
            dfsForAlice(0, 0, 0, amount);
            return aliceIncome;
        }
    };