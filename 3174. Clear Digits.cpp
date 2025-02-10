class Solution {
    public:
        string clearDigits(string s) 
        {
            string ans;
            for(char ch:s)
            {
                if(isalpha(ch)) ans += ch;
                else if(ans.size()) ans.pop_back();
            }
            return ans;
        }
    };