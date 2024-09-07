class Solution {
public:
    int totalMoney(int n) 
    {
        int week = n / 7;
        int rem_days = n % 7;

        int ans = 0;
        for(int i = 0; i < week; i++)
            ans += 28 + (i * 7);

        int cur_puts = week + 1;
        while(rem_days--)
            ans += cur_puts++;
            
        return ans;
    }
};