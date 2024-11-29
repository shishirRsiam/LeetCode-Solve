#define pi pair<int, int>
class Solution {
public:
    bool isValid(int &i, int &j, int &n, int &m) {
        return i >= 0 and j >= 0 and i < n and j < m;
    }
    int dijkstra(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>distance(n, vector<int>(m, INT_MAX));

        priority_queue<pair<int, pi>, vector<pair<int, pi>>, greater<pair<int, pi>>>minHeap;
        minHeap.push({0, {0, 0}});

        vector<pi>directions {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        distance[0][0] = 0;

        while(!minHeap.empty())
        {
            auto [minDistance, idx] = minHeap.top(); minHeap.pop();
            auto [i, j] = idx;

            for(auto [ii, jj] : directions)
            {
                int ci = i + ii, cj = j + jj;
                if(isValid(ci, cj, n, m))
                {
                    int newDistance = minDistance + grid[ci][cj];
                    if(newDistance < distance[ci][cj])
                    {
                        distance[ci][cj] = newDistance;
                        minHeap.push({newDistance, {ci, cj}});
                    }
                }
            }
        }
        return distance[n - 1][m - 1];
    }
    int minimumObstacles(vector<vector<int>>& grid) 
    {
        return dijkstra(grid);
    }
};

// 28 Nov 2022 | 2290. Minimum Obstacle Removal to Reach Corner