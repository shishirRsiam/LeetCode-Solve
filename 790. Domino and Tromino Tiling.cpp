class Solution {
public:
    int mod = 1e9 + 7;
    unordered_map<int, int> memo;
    int numTilings(int n) 
    {
        if (n == 0) return 1;
        if (n == 1) return 1;
        if (n == 2) return 2;

        if (memo.count(n)) return memo[n];

        return memo[n] = (2LL * numTilings(n - 1) % mod + numTilings(n - 3) % mod) % mod;
    }
};