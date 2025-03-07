class Solution {
    public:
        vector<bool> prime;
        vector<int> allPrimes;
        void sieveOfEratosthenes(int n, int m) 
        {
            prime.resize(n + 1, true);
            prime[1] = false;
            for (int p = 2; p * p <= n; p++) 
            {
                if (prime[p] == true) 
                    for (int i = p * p; i <= n; i += p)
                        prime[i] = false;
            }
    
            for (int p = m; p <= n; p++)
                if (prime[p])
                    allPrimes.push_back(p);
        }
        vector<int> closestPrimes(int left, int right) 
        {
            sieveOfEratosthenes(right, left);
            if(allPrimes.size() < 2) return {-1, -1};
    
            int a = allPrimes[0], b = allPrimes[1];
            int mn = (allPrimes[1] - allPrimes[0]), n = allPrimes.size();
            
            for(int i = 0; i < n-1; i++)
            {
                if(mn > (allPrimes[i+1] - allPrimes[i]))
                {
                    mn = (allPrimes[i+1] - allPrimes[i]);
                    a = allPrimes[i], b = allPrimes[i+1];
                }
            }
            return {a, b};
        }
    };