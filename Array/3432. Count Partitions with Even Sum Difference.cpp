class Solution {
public:
    int countPartitions(vector<int>& nums) 
    {
        int ans = 0, left = 0, n = nums.size(); 
        int right = accumulate(nums.begin(), nums.end(), 0);
        for(int i = 0; i < n - 1; i++)
        {
            left += nums[i], right -= nums[i];
            ans += not (abs(right - left) % 2);
        }
        return ans;
    }
};