class Solution {
public:
    int countHomogenous(string s) 
    {
        char prev = '.';
        long ans = 0, count = 0; 
        int mod = 1e9 + 7, n = s.size();
        for(int i = 0; i <= n; i++)
        {
            if(s[i] == prev) count += 1;
            else 
            {
                ans += (count * (count + 1) / 2);
                count = 1, prev = s[i];
            }
        }
        return ans % mod;
    }
};