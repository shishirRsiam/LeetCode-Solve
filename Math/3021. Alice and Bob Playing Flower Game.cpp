class Solution {
public:
    long long flowerGame(int n, int m) 
    {
        long ans = 0;
        int even_count = m / 2, odd_count = (m + 1) / 2;

        for(int i = 1; i <= n; i++)
            ans += (i % 2 ? even_count : odd_count);
        return ans;
    }
};