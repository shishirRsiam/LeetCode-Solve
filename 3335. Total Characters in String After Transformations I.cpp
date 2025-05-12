class Solution {
public:
    int lengthAfterTransformations(string s, int t) 
    {
        int n = s.size();
        long ans = 0, mod = 1e9 + 7;

        vector<long> count(130);
        for(auto &ch : s) count[ch] += 1;

        while(t--)
        {
            vector<long> temp(130);
            for(auto ch = 'z'; ch >= 'a'; ch--)
            {
                if(ch == 'z') temp['a'] = count[ch], temp['b'] = count[ch];
                else temp[ch + 1] += count[ch];
                temp[ch] %= mod;
            }
            count = temp;
        }

        for(auto ch = 'z'; ch >= 'a'; ch--)
            ans += (count[ch] % mod);

        return ans % mod;
    }
};