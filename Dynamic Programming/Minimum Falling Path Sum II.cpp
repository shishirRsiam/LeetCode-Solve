class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n));
        dp[0] = grid[0];
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int Min = INT_MAX;
                for(int k=0;k<n;k++)
                    if(j != k) Min = min(Min, dp[i-1][k]);
                dp[i][j] = Min + grid[i][j];
            }
        }

        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};