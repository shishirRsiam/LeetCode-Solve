#define pi pair<long, int> 
class Solution {
public:
    int mod = 1e9 + 7;
    vector<vector<pair<int, int>>> adj;
    auto Dijkstra(int n)
    {
        vector<long> distance(n, LLONG_MAX), ways(n);
        ways[0] = 1;
        distance[0] = 0;
        
        priority_queue<pi, vector<pi>, greater<pi>> minHeap;
        minHeap.push({0, 0});
        while(!minHeap.empty())
        {
            auto [cost, node] = minHeap.top(); minHeap.pop();
            if(cost > distance[node]) continue;
            for(auto [cNode, cCost] : adj[node])
            {
                long newCost = long(cost) + cCost;
                if(newCost < distance[cNode])
                {
                    ways[cNode] = ways[node];
                    distance[cNode] = newCost;
                    minHeap.push({distance[cNode], cNode});
                }
                else if(newCost == distance[cNode])
                    ways[cNode] = (ways[cNode] + ways[node]) % mod;
            }
        }
        return ways[n - 1];
    }

    int countPaths(int n, vector<vector<int>>& roads) 
    {
        adj.resize(n);
        for(auto &road : roads)
        {
            int u = road[0], v = road[1], c = road[2];
            adj[u].push_back({v, c});
            adj[v].push_back({u, c});
        }  

        return Dijkstra(n);
    }
};