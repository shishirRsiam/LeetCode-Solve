class Solution {
public:
    string generateTag(string caption) 
    {
        string ans = "#";

        bool flag = caption[0] == ' ';
        for(auto &ch : caption)
        {
            if(ans.size() == 100) break;

            ch = (flag ? toupper(ch) : tolower(ch));

            if(ch == ' ') flag = true;
            else ans += ch, flag = false;
        }
        
        ans[1] = tolower(ans[1]);
        return ans;    
    }
};