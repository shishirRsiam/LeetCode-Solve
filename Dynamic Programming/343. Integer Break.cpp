class Solution {
public:
    long ans = 0;
    vector<unordered_map<long, long>> memo;
    void dfs(int sum, int &n, long mul)
    {
        if(sum > n) return;
        if(sum == n) ans = max(ans, mul);

        if(memo[sum][mul]) 
        {
            ans = max(ans, memo[sum][mul]);
            return;
        }

        for(int i = 1; i < n; i++)
            dfs(sum + i, n, mul * i);
        memo[sum][mul] = mul;
    }
    int integerBreak(int n) 
    {
        memo.resize(200);
        dfs(0, n, 1);
        return ans;
    }
};