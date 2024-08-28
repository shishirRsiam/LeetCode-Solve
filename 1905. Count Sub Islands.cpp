class Solution {
public:
    int n, m;
    bool flag;
    bool vst[505][505];
    vector<vector<int>> grid_i, grid_ii;
    void dfs(int i, int j)
    {
        if(i < 0 or j < 0 or i >= n or j >= m or !grid_ii[i][j] or vst[i][j]) return;

        vst[i][j] = true;
        if(!grid_i[i][j]) flag = false;

        dfs(i+1, j);
        dfs(i, j+1);
        dfs(i-1, j);
        dfs(i, j-1);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) 
    {
        int ans = 0;
        grid_i = grid1, grid_ii = grid2;
        n = grid1.size(), m = grid1[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vst[i][j] and grid_ii[i][j])
                {
                    flag = true;
                    dfs(i, j);
                    ans += flag;
                }
            }
        }
        return ans;
    }
};