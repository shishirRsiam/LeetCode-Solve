class Solution {
public:
    string removeOuterParentheses(string s) 
    {
        string ans;
        int cnt = 0;
        for(char ch:s)
        {
            if(ch == '(') 
            {
                if(cnt) ans += ch;
                cnt++;
            }
            else 
            {
                cnt--;
                if(cnt) ans += ch;
            }
        }
        return ans;
    }
};