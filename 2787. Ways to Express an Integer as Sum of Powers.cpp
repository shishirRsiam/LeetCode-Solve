class Solution {
public:
    int mod = 1e9 + 7;
    vector<vector<int>>dp;
    long recursion(int cur_number, long cur_sum, int x, int n)
    {
        if(cur_sum == n) return 1;
        if(cur_sum > n or cur_number > n) return 0;

        if(dp[cur_number][cur_sum] != -1) return dp[cur_number][cur_sum];

        long power = (pow(cur_number, x));

        long add = recursion(cur_number + 1, cur_sum + power, x, n);
        long skip = recursion(cur_number + 1, cur_sum, x, n);
        return dp[cur_number][cur_sum] = ((add + skip) % mod);
    }
    int numberOfWays(int n, int x) 
    {
        dp.resize(n + 1, vector<int>(n + 1, -1));
        return recursion(1, 0, x, n);
    }
};