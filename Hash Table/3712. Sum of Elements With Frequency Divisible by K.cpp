class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) 
    {
        unordered_map<int, int> count;
        for(auto &val : nums)
            count[val] += 1;
        
        int ans = 0;
        for(auto &[val, cnt] : count)
            ans += cnt % k ? 0 : cnt * val;
        return ans;
    }
};