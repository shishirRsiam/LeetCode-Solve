class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) 
    {
        long ans = 0, count = 0;
        for(const int &val : nums)
        {
            if(val) count = 0;
            else count += 1;
            ans += count;
        }
        return ans;
    }
};