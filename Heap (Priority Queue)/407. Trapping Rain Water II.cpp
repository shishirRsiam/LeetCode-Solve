#define pi pair<int, int>
#define pii pair<int, pi>
class Solution {
public:
    int trapRainWater(vector<vector<int>>& grid) 
    {
        int n = grid.size(), m = grid[0].size();
        
        vector<vector<bool>> visited(205, vector<bool>(205));
        vector<pi> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        priority_queue<pii, vector<pii>, greater<pii>> minHeap;
        for(int i = 0; i < n; i++)
        {
            for(auto j : {0, m - 1}) 
            {
                visited[i][j] = true;
                minHeap.push({grid[i][j], {i, j}});
            }
        }
        
        for(int j = 0; j < m - 1; j++)
        {
            for(auto i : {0, n - 1}) 
            {
                visited[i][j] = true;
                minHeap.push({grid[i][j], {i, j}});
            }
        }

        int trapRainWater = 0;
        while(!minHeap.empty())
        {
            auto [height, idx] = minHeap.top(); minHeap.pop();
            auto [i, j] = idx;

            for(auto [ii, jj] : direction)
            {
                int ni = i + ii, nj = j + jj;
                if(ni < 0 or ni == n or nj < 0 or nj == m or visited[ni][nj]) continue;

                visited[ni][nj] = true;
                trapRainWater += max(0, height - grid[ni][nj]);
                minHeap.push({max(height, grid[ni][nj]), {ni, nj}});
            }
        }

        return trapRainWater;
    }
};