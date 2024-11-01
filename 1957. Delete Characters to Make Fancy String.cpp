class Solution {
public:
    string makeFancyString(string s) 
    {
        int n;
        string ans;
        for(auto &ch:s)
        {
            n = ans.size();
            if(n > 1 and ans.back() == ch and ans.back() == ans[n - 2])
            {
                continue;
            }
            ans += ch;
        }
        return ans;
    }
};