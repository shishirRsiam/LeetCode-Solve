class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) 
    {
        sort(begin(nums), end(nums));
        int i = 0, j = 0, ans = 0, n = nums.size();
        while(j < n)
        {
            while(nums[j] - nums[i] > k + k) i++;
            ans = max(ans, j - i + 1);
            j++;
        }    
        return ans;
    }
};