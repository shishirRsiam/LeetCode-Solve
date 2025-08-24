class Solution {
public:
    int longestSubarray(vector<int>& nums) 
    {
        int ans = 0, n = nums.size();
        int i = 0, j = 0, zero_count = 0;
        while(j < n)
        {
            zero_count += nums[j++] == 0;
            while(zero_count > 1) 
                zero_count -= nums[i++] == 0;
            ans = max(ans, j - i - zero_count);
        }
        ans -= ans == n;
        return ans;
    }
};