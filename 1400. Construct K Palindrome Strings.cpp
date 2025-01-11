class Solution {
public:
    bool canConstruct(string s, int k) 
    {
        vector<int> freq(26);
        for(auto ch : s) freq[ch - 'a'] += 1;

        int oddCount = 0;
        for(int i = 0; i < 26; i++)
            oddCount += freq[i] % 2;
        return s.size() >= k and oddCount <= k;
    }
};