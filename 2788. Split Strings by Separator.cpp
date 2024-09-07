class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) 
    {
        vector<string>ans;
        string temp;
        for(auto s:words)
        {
            for(auto ch:s)
            {
                if(ch == separator)
                {
                    if(temp.size())ans.push_back(temp);
                    temp = "";
                }
                else temp += ch;
            }
            if(temp.size() and s.back() != separator)
            {
                ans.push_back(temp);
                temp = "";
            }
        }
        return ans;
    }
};