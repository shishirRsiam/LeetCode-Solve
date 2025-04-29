#define pi pair<int, int>
#define pii pair<int, pi>
class Solution {
public:
bool findSafeWalk(vector<vector<int>>& grid, int health) 
{
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m));

    vector<vector<int>> distance(n, vector<int>(m, INT_MAX));
    distance[0][0] = grid[0][0];

    priority_queue<pii, vector<pii>, greater<pii>> minHeap;
    minHeap.push({distance[0][0], {0, 0}});

    vector<pi> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    while(not minHeap.empty())
    {
        auto [cost, idx] = minHeap.top(); minHeap.pop();
        auto [i, j] = idx;
        if(distance[i][j] < cost) continue;

        for(auto [ii, jj] : dir)
        {
            int new_i = i + ii, new_j = j + jj;
            if(new_i < 0 or new_j < 0 or new_i == n or new_j == m) 
                continue;
            if(grid[new_i][new_j] + cost < distance[new_i][new_j])
            {
                distance[new_i][new_j] = grid[new_i][new_j] + cost;
                minHeap.push({distance[new_i][new_j], {new_i, new_j}});
            }
        }
        if(i == n - 1 and j == m - 1) break;
    }
    
    return distance[n - 1][m - 1] < health;
}
};