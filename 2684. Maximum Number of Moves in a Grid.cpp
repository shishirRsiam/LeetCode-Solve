class Solution {
public:
    int n, m;
    vector<vector<int>> mat, dp;
    int solve(int i, int j, int val)
    {
        if(i < 0 or i >= n or j < 0 or j >= m or mat[i][j] <= val) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int dir1 = solve(i - 1, j + 1, mat[i][j]);
        int dir2 = solve(i, j + 1, mat[i][j]);
        int dir3 = solve(i + 1, j + 1, mat[i][j]);

        return dp[i][j] = max({dir1, dir2, dir3}) + 1;
    }
    int maxMoves(vector<vector<int>>& grid) 
    {
        mat = grid;
        n = mat.size(), m = mat[0].size();
        dp.resize(n, vector<int>(m, -1));

        int ans = 0;
        for(int i = 0; i < n; i++)
            ans = max(ans, solve(i, 0, -1));
        return ans - 1;
    }
};