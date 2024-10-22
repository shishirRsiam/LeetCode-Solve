class Solution {
public:
    vector<string> stringSequence(string target) 
    {
        string s;
        vector<string>ans;
        int n = target.size();
        for(int i = 0; i < n; i++)
        {
            s += 'a';
            for(char ch = 'a'; ch <= 'z'; ch++)
            {
                s[i] = ch;
                ans.push_back(s);
                if(ch == target[i]) break;
            }
        }
        return ans;    
    }
};