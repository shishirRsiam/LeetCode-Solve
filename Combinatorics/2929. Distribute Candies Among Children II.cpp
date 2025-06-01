class Solution {
public:
    long long distributeCandies(int n, int limit) 
    {
        long ans = 0;
        for(int i = 0; i <= limit; i++)
        {
            long j = n - i;
            if(limit + limit < j or j < 0) continue;

            ans += 1;
            if(j <= limit) ans += j;
            else ans += limit - (j - limit);
        }
        return ans;
    }
};