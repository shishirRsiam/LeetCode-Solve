class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) 
    {
        int n = nums.size();
        unordered_map<int,int> count;
        int maxVal = *max_element(nums.begin(), nums.end());

        long long ans = 0, i = 0, j = 0;
        while(j < n)
        {
            count[nums[j]]++;
            while(count[maxVal] == k and i <= j)
            {
                ans += n - j;
                count[nums[i++]]--;
            }
            j++;
        }
        return ans;
    }
};