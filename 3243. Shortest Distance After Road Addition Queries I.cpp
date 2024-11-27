#define pi pair<int,int>
class Solution {
public:
    int dijkstra(int n, vector<pi> adj[])
    {
        vector<int> distance(n, INT_MAX);
        priority_queue<pi, vector<pi>, greater<pi>>minHeap;
        distance[0] = 0;
        minHeap.push({0, 0});

        while(!minHeap.empty())
        {
            auto [curDis, curNode] = minHeap.top(); minHeap.pop();
            
            if(curDis > distance[curNode]) continue;

            for(auto [neibor, weight] : adj[curNode])
            {
                if(distance[curNode] + weight < distance[neibor])
                {
                    distance[neibor] = distance[curNode] + weight;
                    minHeap.push({distance[neibor], neibor});
                }
            }
        }
        return distance.back();
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) 
    {
        vector<pi> adj[n];
        for(int i = 0; i < n - 1; i++)
            adj[i].push_back({i + 1, 1});

        vector<int>ans;
        for(auto vec : queries)
        {
            adj[vec[0]].push_back({vec[1], 1});
            ans.push_back(dijkstra(n, adj));
        }
        return ans;
    }
};