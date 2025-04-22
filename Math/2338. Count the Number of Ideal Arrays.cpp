class Solution {
public:
    const int M = 1e9 + 7; // Modulo for large number operations to avoid overflow
    const int MAX_LEN = 14; // Max possible length of sequence (as per constraints)

    // Recursively finds all increasing sequences ending with `m` and counts them
    void findSets(int m, vector<int>& count, vector<vector<int>>& dp) 
    {
        // If already computed, skip recomputation
        if (dp[m][1]) return;

        // A sequence of length 1 ends with `m` by default
        dp[m][1] = 1;
        count[1]++;

        // Try all divisors of m to build longer sequences
        for (int div = 2; div <= m; ++div) 
        {
            if (m % div == 0) 
            {
                findSets(m / div, count, dp); // Recurse for smaller divisor

                // Extend sequences of all lengths from divisor to length + 1
                for (int len = 1; len < MAX_LEN; ++len) 
                {
                    if (dp[m / div][len]) 
                    {
                        dp[m][len + 1] = (dp[m][len + 1] + dp[m / div][len]) % M;
                        count[len + 1] = (count[len + 1] + dp[m / div][len]) % M;
                    }
                }
            }
        }
    }

    // Fast modular exponentiation: computes (a^b) % M
    long long power(long long a, long long b) 
    {
        long long result = 1;
        while (b > 0) 
        {
            if (b % 2) result = (result * a) % M;
            a = (a * a) % M;
            b /= 2;
        }
        return result;
    }

    // Computes C(n, r) % M using modular inverse of factorial
    int modularnCr(int n, int r, const vector<long long>& fact) 
    {
        if (r < 0 || r > n) return 0;
        long long denom = (fact[r] * fact[n - r]) % M;              // denominator = r!(n-r)!
        return (fact[n] * power(denom, M - 2)) % M;                 // C(n, r) = n! / (r!(n-r)!) using Fermat's Little Theorem
    }

    // Main function to calculate number of ideal arrays of length n with max element <= maxVal
    int idealArrays(int n, int maxVal) 
    {
        vector<vector<int>> dp(maxVal + 1, vector<int>(MAX_LEN + 1, 0)); // dp[val][len] = # of sequences ending at val with length len
        vector<int> count(MAX_LEN + 1, 0);                               // count[len] = total sequences of length len

        // Build all sequences for values from 1 to maxVal
        for (int val = 1; val <= maxVal; ++val) 
            findSets(val, count, dp);

        // Precompute factorials for C(n, r)
        vector<long long> fact(n + 1, 1);
        for (int i = 2; i <= n; ++i) 
            fact[i] = (fact[i - 1] * i) % M;

        // Total result = sum over all possible sequence lengths
        long long result = 0;
        for (int len = 1; len <= MAX_LEN && len <= n; ++len) 
        {
            if (count[len] > 0) 
            {
                long long combinations = modularnCr(n - 1, len - 1, fact); // # of ways to choose positions
                result = (result + (count[len] * combinations) % M) % M;   // add contribution of this length
            }
        }

        return result;
    }
};