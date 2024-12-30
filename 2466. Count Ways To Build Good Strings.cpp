class Solution {
public:
    int mod = 1e9 + 7;
    unordered_map<long, int> dp;
    int solve(int &low, int &high, int &zero, int &one, long curStrSize)
    {
        if(curStrSize > high) return 0;
        if(dp.count(curStrSize)) return dp[curStrSize];

        long count = curStrSize >= low ? 1 : 0;
        count += solve(low, high, zero, one, curStrSize + zero);
        count += solve(low, high, zero, one, curStrSize + one);
        return dp[curStrSize] = count % mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) 
    {
        return solve(low, high, zero, one, 0);
    }   
};