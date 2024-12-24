class Solution {
public:
    pair<int, int> getMaxDiamiter(vector<vector<int>> &graph, int startNode)
    {
        vector<int> distance(graph.size() + 1, -1);
        distance[startNode] = 0;

        queue<int> queue;
        queue.push(startNode);
        int maxDiamiterNode = startNode, maxDiamiter = 0;
        while(!queue.empty())
        {
            auto node = queue.front(); queue.pop();
            for(auto neighbor : graph[node])
            {
                if(distance[neighbor] != -1) continue;

                queue.push(neighbor);
                distance[neighbor] = distance[node] + 1;
                
                if(distance[neighbor] > maxDiamiter)
                {
                    maxDiamiterNode = neighbor;
                    maxDiamiter = distance[neighbor];
                }
            }
        }
        return {maxDiamiterNode, maxDiamiter};
    }
    vector<vector<int>> buildAdjList(const vector<vector<int>>& edges) 
    {
        vector<vector<int>> graph(edges.size() + 1);
        for (const auto& edge : edges) 
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        return graph;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) 
    {
        auto graph1 = buildAdjList(edges1), graph2 = buildAdjList(edges2);

        auto [Graph1_tempNode, Graph1_tempDiamiter] = getMaxDiamiter(graph1, 0);
        auto [Graph1_maxDiamiterNode, Graph1_maxDiamiter] = getMaxDiamiter(graph1, Graph1_tempNode);

        auto [Graph2_tempNode, Graph2_tempDiamiter] = getMaxDiamiter(graph2, 0);
        auto [Graph2_maxDiamiterNode, Graph2_maxDiamiter] = getMaxDiamiter(graph2, Graph2_tempNode);

        int added_Diamiter = ((Graph1_maxDiamiter + 1) / 2) + ((Graph2_maxDiamiter + 1) / 2) + 1;
        return max({Graph1_maxDiamiter, Graph2_maxDiamiter, added_Diamiter});
    }
};