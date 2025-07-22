class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) 
    {
        unordered_set<int> seen;
        int maxSum = 0, sum = 0;
        int i = 0, j = 0, n = nums.size();
        while(j < n)
        {
            sum += nums[j];
            while(seen.count(nums[j]))
            {
                sum -= nums[i];
                seen.erase(nums[i++]);
            }
            seen.insert(nums[j++]);
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};