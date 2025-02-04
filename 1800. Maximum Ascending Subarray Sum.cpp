class Solution {
public:
    int maxAscendingSum(vector<int>& nums) 
    {
        int n = nums.size(), sum = nums[0], maxSum = nums[0];   
        for(int i = 1; i < n; i++)
        {
            if(nums[i] <= nums[i - 1]) sum = 0;
            sum += nums[i];
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};