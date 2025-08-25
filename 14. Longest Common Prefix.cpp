class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        string cur, first_str = strs[0];
        for(const char &ch : first_str)
        {
            cur += ch;
            for(const string &s : strs)
            {
                if(s.substr(0, cur.size()) != cur)
                {
                    cur.pop_back();
                    return cur;
                }
            }
        }
        return cur;
    }
};