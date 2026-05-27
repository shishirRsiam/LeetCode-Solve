class Solution {
public:
    int numberOfSpecialChars(string s) 
    {
        map<char,int>mp;
        int ans = 0, n = s.size();
        for(int i=0;i<n;i++) 
        {
            char ch = s[i];
            if(islower(ch)) mp[ch] = i+1;
            else if(mp[ch] == 0) mp[ch] = i+1;
        }
        
        for(char i='a';i<='z';i++)
        {
            int x = mp[i], y = mp[i - 'a' + 'A'];
            if(x and y and x < y) ans++;
        }
        return ans;
    }
};