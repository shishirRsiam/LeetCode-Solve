class Solution {
public:
    bool isCircularSentence(string s) 
    {
        if(s[0] != s.back()) return false;

        int n = s.size();
        for(int i = 1; i < n - 1; i++)
        {
            if(s[i] == ' ')
            {
                if(s[i - 1] != s[i + 1]) 
                    return false;
            }
        }
        return true;
    }
};