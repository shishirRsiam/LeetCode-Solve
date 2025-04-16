class Solution {
public:
    long long countGood(vector<int>& nums, int k) 
    {
        long ans = 0, pairs = 0;
        unordered_map<int, int> count;
        int i = 0, j = 0, n = nums.size();
        while(j < n)
        {
            pairs += count[nums[j]];
            count[nums[j++]] += 1;
            while(pairs >= k)
            {
                ans += (n - j) + 1;
                pairs -= --count[nums[i++]];
            }
        }
        return ans;
    }
};