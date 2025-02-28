class Solution {
    public:
        int countPrimeSetBits(int left, int right) 
        {
            int ans = 0;
            
            unordered_set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
            for(int i = left; i <= right; i++)
                ans += primes.count(bitset<32>(i).count());
    
            return ans;    
        }
    };