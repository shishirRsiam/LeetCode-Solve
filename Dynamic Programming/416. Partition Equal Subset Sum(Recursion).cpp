class Solution {
public:

    int dp[205][20005];

    bool subset(int n, int sum, vector<int>& nums)
    {
        if(!sum) return true;
        if(!n) return false;
        if(dp[n][sum] != -1) return dp[n][sum];

        bool flag = subset(n-1, sum, nums);
        if(nums[n-1]<=sum)
            flag = flag or subset(n-1, sum - nums[n-1], nums);
        return dp[n][sum] = flag;
    }

    bool canPartition(vector<int>& nums) 
    {
        int sum = 0;
        for(int v:nums) sum += v;
        if(sum%2) return false;
        memset(dp, -1, sizeof(dp));
        return subset(nums.size(), sum/2, nums);
    }
};