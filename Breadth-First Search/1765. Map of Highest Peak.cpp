class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) 
    {
        int n = isWater.size(), m = isWater[0].size();
        queue<pair<int, int>> que;
        vector<vector<int>> ans(n, vector<int>(m, INT_MAX));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(isWater[i][j])
                {
                    ans[i][j] = 0;
                    que.push({i, j});
                }
            }
        }
        
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(!que.empty())
        {
            auto [i, j] = que.front(); que.pop();
            for(auto [ii, jj] : dir)
            {
                int ni = i + ii, nj = j + jj;
                if(ni < 0 or ni == n or nj < 0 or nj == m) continue;
                if(ans[i][j] + 1 < ans[ni][nj])
                {
                    ans[ni][nj] = ans[i][j] + 1;
                    que.push({ni, nj});
                }
            }
        }
        return ans;
    }
};