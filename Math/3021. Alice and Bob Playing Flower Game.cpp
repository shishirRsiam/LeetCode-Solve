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

class Solution {
public:
    long long flowerGame(int n, int m) 
    {
        long even_count1 = n / 2, odd_count1 = (n + 1) / 2;
        long even_count2 = m / 2, odd_count2 = (m + 1) / 2;
        return (even_count1 * odd_count2) + (odd_count1 * even_count2);
    }
};