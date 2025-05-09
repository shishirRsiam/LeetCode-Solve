class Solution {
public:
    long long totalHalfPermutations = 0;
    int length, totalDigitSum, MOD = 1e9 + 7;

    // Binary exponentiation to calculate a^b % MOD
    int power(long long base, long long exponent) 
    {
        if (exponent == 0) return 1;

        long long half = power(base, exponent / 2);

        long long result = (half * half) % MOD;
        if (exponent % 2) result = (result * base) % MOD;
        
        return result;
    }

    int countWays(int digit, int evenCount, int currentSum,
                  vector<int>& digitFrequency, vector<long long>& invFactorial,
                  vector<vector<vector<int>>>& dp) {

        if (digit == 10) 
        {
            if (currentSum == totalDigitSum / 2 and evenCount == (length + 1) / 2)
                return totalHalfPermutations;
            return 0;
        }

        if (dp[digit][evenCount][currentSum] != -1) 
            return dp[digit][evenCount][currentSum];

        long long ways = 0;

        for (int countAtEven = 0; countAtEven <= min(digitFrequency[digit], (length + 1) / 2 - evenCount); countAtEven++) 
        {
            int countAtOdd = digitFrequency[digit] - countAtEven;
            long long divisor = (invFactorial[countAtEven] * invFactorial[countAtOdd]) % MOD;

            long long next = countWays(digit + 1,
                                       evenCount + countAtEven,
                                       currentSum + digit * countAtEven,
                                       digitFrequency, invFactorial, dp);

            ways = (ways + (next * divisor) % MOD) % MOD;
        }

        return dp[digit][evenCount][currentSum] = ways;
    }

    int countBalancedPermutations(string num) 
    {
        length = num.length();
        totalDigitSum = 0;

        vector<int> digitFrequency(10, 0);
        for (char ch : num) 
        {
            int digit = ch - '0';
            totalDigitSum += digit;
            digitFrequency[digit] += 1;
        }

        if (totalDigitSum % 2) return 0;

        // Precompute factorials
        vector<long long> factorial(length + 1, 1);
        for (int i = 2; i <= length; i++) 
            factorial[i] = (factorial[i - 1] * i) % MOD;

        // Precompute inverse factorials using Fermat's little theorem
        vector<long long> invFactorial(length + 1, 1);
        for (int i = 0; i <= length; i++) 
            invFactorial[i] = power(factorial[i], MOD - 2);

        totalHalfPermutations = (1LL * factorial[(length + 1) / 2] * factorial[length / 2]) % MOD;

        vector<vector<vector<int>>> dp(10, vector<vector<int>>((length + 1) / 2 + 1, vector<int>(totalDigitSum + 1, -1)));

        return countWays(0, 0, 0, digitFrequency, invFactorial, dp);
    }
};