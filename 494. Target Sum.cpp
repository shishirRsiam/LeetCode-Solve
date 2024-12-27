class Solution {
public:
    map<pair<int,int>,int>dp;
    int solve(int n, int sum, vector<int>& nums)
    {
        if(!n) return sum == 0;

        if(dp.find({n,sum}) != dp.end()) return dp[{n, sum}];

        int add = solve(n - 1, sum - nums[n-1], nums);
        int subtract = solve(n - 1, sum + nums[n - 1], nums);
        return dp[{n, sum}] = add + subtract;
    }
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        return solve(nums.size(), target, nums);
    }
};