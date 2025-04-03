class Solution {
public:
    int minimumSum(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> minLeft(n), minRight(n);    
        int minLeftVal = INT_MAX, minRightVal = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            minLeft[i] = minLeftVal;
            minRight[n - i - 1] = minRightVal;
            minLeftVal = min(minLeftVal, nums[i]);
            minRightVal = min(minRightVal, nums[n - i - 1]);
        }

        int ans = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] <= minLeft[i] or nums[i] <= minRight[i])
                continue;
            ans = min(ans, minLeft[i] + nums[i] + minRight[i]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};