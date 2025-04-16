class Solution {
public:
    int numSub(string s) 
    {
        int mod = 1e9 + 7;
        long ans = 0, count = 0, n = s.size();
        for(int i = 0; i <= n; i++)
        {
            if(s[i] == '1') count += 1;
            else 
            {
                ans += (count * (count + 1) / 2) % mod;
                count = 0;
            }
        }
        return ans % mod;
    }
};