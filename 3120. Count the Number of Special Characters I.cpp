class Solution {
public:
    int numberOfSpecialChars(string word) 
    {
        set<char>ch(word.begin(), word.end());
        map<int,char>mp;
        for(auto c:ch)
        {
            c = tolower(c);
            mp[c]++;
        }

        int ans = 0;
        for(auto x:mp)
            if(x.second == 2) ans++;
        return ans;
    }
};