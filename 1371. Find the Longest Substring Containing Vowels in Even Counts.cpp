class Solution
{
public:
    int findTheLongestSubstring(string s)
    {
        unordered_map<char, int> voules;
        voules['a'] = 1;
        voules['e'] = 2;
        voules['i'] = 4;
        voules['o'] = 8;
        voules['u'] = 16;

        unordered_map<int, int> lastSeenIndex;
        lastSeenIndex[0] = -1;

        int maxLen = 0, mask = 0, n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (voules.find(s[i]) != voules.end())
            {
                mask ^= voules[s[i]];
            }
            if (!mask or lastSeenIndex.find(mask) != lastSeenIndex.end())
            {
                maxLen = max(maxLen, i - lastSeenIndex[mask]);
            }
            else
            {
                lastSeenIndex[mask] = i;
            }
        }
        return maxLen;
    }
};