class Solution {
public:
    bool isPrefixAndSuffix(string s1, string s2)
    {
        if(s1.size() > s2.size()) return false;
        bool isPrefix = s2.substr(0, s1.size()) == s1;
        bool isSuffix = s2.substr(s2.size() - s1.size()) == s1;
        return isPrefix and isSuffix;
    }
    int countPrefixSuffixPairs(vector<string>& words) 
    {
        int ans = 0, n = words.size();
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                ans += isPrefixAndSuffix(words[i], words[j]);
        return ans;
    }
};