class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int mod, vector<int>& nums) 
    {
        if(i == nums.size())
            return (mod == 0 ? 0 : INT_MIN);

        int &res = dp[i][mod];
        if(res != -1)
            return res;

        int take = nums[i] + solve(i + 1, (mod + nums[i] % 3) % 3, nums);
        int skip = solve(i + 1, mod, nums);

        return res = max(take, skip);
    }

    int maxSumDivThree(vector<int>& nums) 
    {
        int n = nums.size();
        dp.assign(n + 1, vector<int>(3, -1));

        int res = solve(0, 0, nums);
        return res < 0 ? 0 : res;
    }
};