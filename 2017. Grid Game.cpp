class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) 
    {
        int n = grid[0].size();
        vector<long> prefRowOne(n), prefRowTwo(n);

        prefRowOne[0] = grid[0][0];
        for(int i = 1; i < n; i++)
            prefRowOne[i] = prefRowOne[i - 1] + grid[0][i];

        prefRowTwo[n - 1] = grid[1][n - 1];
        for(int i = n - 2; i >= 0; i--)
            prefRowTwo[i] = prefRowTwo[i + 1] + grid[1][i];

        long robotTwoMaxCollect = LONG_MAX;
        for(int i = 0; i < n; i++)
        {
            long fromRowOne = prefRowOne.back() - prefRowOne[i];
            long fromRowTwo = prefRowTwo[0] - prefRowTwo[i];
            robotTwoMaxCollect = min(robotTwoMaxCollect, max(fromRowOne, fromRowTwo));
        }
        return robotTwoMaxCollect;
    }
};