class Solution {
public:
    int countAsterisks(string s) 
    {
        int ans = 0, flag = true;
        for(char ch:s)
        {
            if(flag and ch == '*') ans++;
            if(ch == '|') flag = !flag;
        }
        return ans;
    }
};