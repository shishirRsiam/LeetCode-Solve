class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) 
    {
        long long ans = 0, sum = 0;
        int i = 0, j = 0, n = nums.size();
        while(j < n)
        {
            sum += nums[j];
            while(sum * (j - i + 1) >= k) 
                sum -= nums[i++];
            ans += j - i + 1;
            j++;
        }
        return ans;
    }
};