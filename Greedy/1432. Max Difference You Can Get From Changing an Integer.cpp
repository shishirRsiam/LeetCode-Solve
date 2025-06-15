class Solution {
public:
    auto manupulateString(char ch, char changeChar, string s)
    {
        for(auto &c : s)
            c = (c == ch ? changeChar : c);

        if(s[0] == '0') s[0] = '9';
        return s;
    }
    int maxDiff(int num) 
    {
        auto s = to_string(num), maxS = s, minS = s; 
        unordered_set<char> st(begin(s), end(s));

        for(auto ch : st)
            maxS = max(maxS, manupulateString(ch, '9', s));

        for(auto ch : st)
        {
            auto s1 = manupulateString(ch, '0', s);
            auto s2 = manupulateString(ch, '1', s);
            minS = min({minS, s1, s2});
        }

        return stoi(maxS) - stoi(minS);
    }
};