class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        sort(begin(nums), end(nums));  

        int maxIndex = 0, n = nums.size();
        vector<int> dp(n, 1), prev(n, -1), ans;
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if((nums[i] % nums[j] == 0) and dp[i] < dp[j] + 1)
                    prev[i] = j, dp[i] = dp[j] + 1;
            }
            if(dp[maxIndex] < dp[i]) maxIndex = i;
        }

        while(maxIndex != -1)
        {
            ans.push_back(nums[maxIndex]);
            maxIndex = prev[maxIndex];
        }

        reverse(begin(ans), end(ans));
        return ans;
    }
};