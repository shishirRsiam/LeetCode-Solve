class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        unordered_map<char, int> mp, mp2;
        for (auto ch : s1)
            mp2[ch]++;

        int i = 0, j = 0, k = s1.size(), n = s2.size();
        while (j < n)
        {
            mp[s2[j++]]++;
            if (j - i == k)
            {
                if (mp == mp2)
                    return true;
                mp[s2[i]]--;
                if (mp[s2[i]] == 0)
                    mp.erase(s2[i]);
                i++;
            }
        }
        return false;
    }
};