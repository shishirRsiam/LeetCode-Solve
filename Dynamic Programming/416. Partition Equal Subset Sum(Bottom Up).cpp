class Solution {
public:
    bool canPartition(vector<int>& nums) 
    {
        int sum = 0, n = nums.size();
        for(int v:nums) sum += v;
        if(sum%2) return false;
        sum /= 2;
        
        bool dp[n+1][sum+1];
        dp[0][0] = true;
        for(int i=1;i<=sum;i++) dp[0][i] = false;

        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                dp[i][j] = dp[i-1][j];
                if(nums[i-1] <= j)
                    dp[i][j] = dp[i][j] or dp[i-1][j - nums[i-1]];
            }
        }
        return dp[n][sum];
    }
};