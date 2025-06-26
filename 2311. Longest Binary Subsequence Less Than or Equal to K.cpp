class Solution {
public:
    void removeBits(string &bits, int &k) 
    {
        while (!bits.empty()) 
        {
            try {
                long num = stoll(bits, nullptr, 2);
                if (num <= k) break;
                bits.erase(bits.begin());
            } catch (const out_of_range &e) {
                bits.erase(bits.begin());
            }
        }
    }

    int longestSubsequence(string s, int k) 
    {
        string bits;
        int ans = 0, n = s.size();

        for (int i = n - 1; i >= 0; i--) 
        {
            bits.insert(bits.begin(), s[i]);
            removeBits(bits, k);

            try {
                long num = stoll(bits, nullptr, 2);
                if (num <= k)
                    ans = max(ans, (int)bits.size());
            } catch (const out_of_range &e) {
                continue;
            }
        }
        return ans;
    }
};