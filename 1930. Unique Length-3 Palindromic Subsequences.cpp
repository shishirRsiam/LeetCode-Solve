class Solution {
public:
    int countPalindromicSubsequence(string s) 
    {
        int n = s.size();
        unordered_map<char, int> minIdx, maxIdx;
        for(int ch = 'a'; ch <= 'z'; ch++)
            minIdx[ch] = INT_MAX, maxIdx[ch] = INT_MIN;

        for(int i = 0; i < n; i++)
        {
            minIdx[s[i]] = min(minIdx[s[i]], i);
            maxIdx[s[i]] = max(maxIdx[s[i]], i);
        }    

        int ans = 0;
        for(int ch = 'a'; ch <= 'z'; ch++)
        {
            if(minIdx[ch] == INT_MAX or minIdx[ch] == maxIdx[ch]) continue;
            unordered_set<char> seen;
            for(int i = minIdx[ch] + 1; i < maxIdx[ch]; i++)
            {
                if(seen.size() == 26) break;
                if(seen.count(s[i])) continue;
                seen.insert(s[i]);
                ans += 1;
            }
        }
        return ans;
    }
};