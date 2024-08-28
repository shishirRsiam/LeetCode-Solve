class Solution {
public:
    const int N = 1e4+5;
    typedef pair<double, int> pi;
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) 
    {
        vector<pi>adj[N];
        int sz = edges.size();
        for(int i=0;i<sz;i++)
        {
            int u = edges[i][0], v = edges[i][1];
            double cost = succProb[i];
            adj[u].push_back({cost, v});
            adj[v].push_back({cost, u});
        }

        vector<double>Prob(N);
        Prob[start] = 1.0;
        priority_queue<pi>pq;
        pq.push({1.0, start});
        while(!pq.empty())
        {
            auto [cost, node] = pq.top(); pq.pop();
            if(node == end) return cost;
            for(auto [ccost, cnode]:adj[node])
            {
                double newcost = cost * ccost;
                if(newcost > Prob[cnode])
                {
                    Prob[cnode] = newcost;
                    pq.push({newcost, cnode});
                }
            }
        }

        return 0.0;
    }
};