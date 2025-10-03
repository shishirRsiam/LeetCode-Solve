using tpl = tuple<int, int, int>;
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) 
    {
        int n = heightMap.size(), m = heightMap[0].size();
        priority_queue<tpl, vector<tpl>, greater<tpl>> minHeap;
        vector<vector<bool>> visited(n + 1, vector<bool>(m + 1));

        for(int i = 0; i < n; i++)
        {
            for(auto j : {0, m - 1})
            {
                visited[i][j] = true;
                minHeap.push({heightMap[i][j], i, j});
            }
        }
        
        for(int j = 0; j < m; j++)
        {
            for(auto i : {0, n - 1})
            {
                visited[i][j] = true;
                minHeap.push({heightMap[i][j], i, j});
            }
        }

        int trapRainWater = 0;
        vector<pair<int, int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(not minHeap.empty())
        {
            auto [height, i, j] = minHeap.top(); minHeap.pop();

            for(auto [ci, cj] : direction)
            {
                int ni = ci + i, nj = cj + j;
                if(ni < 0 or ni >= n or nj < 0 or nj >= m or visited[ni][nj])
                    continue;

                visited[ni][nj] = true;
                trapRainWater += max(0, height - heightMap[ni][nj]);
                minHeap.push({max(height, heightMap[ni][nj]), ni, nj});
            }
        }
        return trapRainWater;
    }
};