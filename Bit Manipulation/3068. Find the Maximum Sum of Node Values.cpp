class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) 
    {
        long ans = 0, count = 0, minXor = INT_MAX;
        for(auto &val : nums)
        {
            if(val < (val xor k))
            {
                count += 1;
                ans += (val xor k);
            }
            else ans += val;
            minXor = min(minXor, long(abs(val - (val xor k))));
        }  
        if(count % 2) ans -= minXor;
        return ans;
    }
};