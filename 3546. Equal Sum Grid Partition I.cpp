class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) 
    {
        int n = grid.size(), m = grid[0].size();

        long allRowSum = 0, allColSum = 0;
        vector<long> rowSum(n), colSum(m);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                allRowSum += grid[i][j], allColSum += grid[i][j];
                rowSum[i] += grid[i][j], colSum[j] += grid[i][j];
            }
        }

        long curSum = 0;
        for(auto &sum : rowSum)
        {
            curSum += sum;
            if(curSum + curSum == allRowSum)
                return true;
        }

        curSum = 0;
        for(auto &sum : colSum)
        {
            curSum += sum;
            if(curSum + curSum == allRowSum)
                return true;
        }

        return false;
    }
};