class Solution {
public:
    char kthCharacter(int k) 
    {
        string s = "ab";
        string temp;
        while(s.size() < k)
        {
            temp = s;
            for(auto &ch:temp)
            {
                if(ch == 'z') ch = 'a';
                else ch = ch + 1;
            }
            s += temp;
        }
        return s[k - 1];
    }
};

/* 
Initially, word = "a". We need to do the operation three times:

Generated string is "b", word becomes "ab".
Generated string is "bc", word becomes "abbc".
Generated string is "bccd", word becomes "abbcbccd".
*/