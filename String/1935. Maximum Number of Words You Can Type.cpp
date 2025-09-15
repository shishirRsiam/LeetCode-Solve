class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) 
    {
        string s;
        int ans = 0;
        stringstream ss(text);
        while(ss >> s)
        {
            bool flag = true;
            for(char c : s)
            {
                if(brokenLetters.find(c) != -1)
                {
                    flag = false;
                    break;
                }
            }
            ans += flag;
        }
        return ans;
    }
};