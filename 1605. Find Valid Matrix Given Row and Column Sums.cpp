class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) 
    {
        int n = rowSum.size(), m = colSum.size();

        vector<vector<int>> ans(n, vector<int>(m));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int &row_sum = rowSum[i], &col_sum = colSum[j];
                int min_sum = min(row_sum, col_sum);

                ans[i][j] = min_sum;
                row_sum -= min_sum, col_sum -= min_sum;
            }
        }
        return ans;   
    }
};