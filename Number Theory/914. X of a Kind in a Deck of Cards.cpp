class Solution {
public:
    vector<int> getAllPrimeNumber(int n)
    {
        vector<int> isPrime(n + 5, true);
        for(int i = 2; i <= sqrt(n); i++)
        {
            for(int j = i + i; j <= n; j += i)
                isPrime[j] = false;
        }

        vector<int> primes;
        for(int i = 2; i <= n; i++)
            if(isPrime[i]) primes.push_back(i);
        return primes;
    }
    bool hasGroupsSizeX(vector<int>& deck) 
    {
        unordered_map<int, int> store;
        for(auto &val : deck) store[val] += 1;
        
        vector<int> primes = getAllPrimeNumber(1e5 + 5);
        for(auto prime : primes)
        {
            bool isPossible = true, isImpossible = false;
            for(auto [val, count] : store)
            {
                if(count == 1 or count < prime) 
                {
                    isImpossible = true;
                    break;
                }
                if(count % prime)
                {
                    isPossible = false;
                    break;
                }
            }
            if(isImpossible) return false;
            if(isPossible) return true;
        }
        return false;
    }
};