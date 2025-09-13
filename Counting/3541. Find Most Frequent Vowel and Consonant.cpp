class Solution {
public:
    auto isVowel(char ch)
    {
        return ch == 'a' or ch == 'e' or ch == 'i' or ch =='o' or ch == 'u';
    }
    int maxFreqSum(string s) 
    {
        vector<int> count(26);
        for(const char &ch : s)
            count[ch - 'a'] += 1;
        
        int maxVowelCount = 0, maxConsonentCount = 0;
        for(int i = 0; i < 26; i++)
        {
            if(isVowel(i + 'a'))
                maxVowelCount = max(maxVowelCount, count[i]);
            else maxConsonentCount = max(maxConsonentCount, count[i]);
        }
        return maxVowelCount + maxConsonentCount;
    }
};