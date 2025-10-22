class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) 
    {
        map<long, long> diffArr;
        unordered_map<long, long> count;

        for (auto &val : nums) 
        {
            long min_range = (long)val - k;
            long max_range = (long)val + k;

            count[val] += 1;
            
            diffArr[val] += 0;
            diffArr[min_range] += 1;
            diffArr[max_range + 1] -= 1;
        }

        long ans = 0, prefixSum = 0;
        for (auto &[val, delta] : diffArr) 
        {
            prefixSum += delta;
            ans = max(ans, min(prefixSum, count[val] + numOperations));
        }
        return ans;
    }
};