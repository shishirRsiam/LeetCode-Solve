class Solution {
public:
    string clearStars(string s) 
    {
        int cnt = count(s.begin(), s.end(), '*');
        if(cnt + cnt == s.size()) return "";
        
        int n = s.size(), idx;
        map<char, vector<int>>mp;
        for(int i=0;i<n;i++)
        {
            char ch = s[i];
            if(ch == '*')
            {
                for(auto [c, vec] : mp)
                {
                    if(vec.size()) 
                    {
                        idx = vec.back();
                        mp[c].pop_back();
                        s[idx] = '$';
                        break;
                    }
                }
            }
            else mp[ch].push_back(i);
        }

        string ans;
        for(auto &ch : s)
            if(isalpha(ch)) ans += ch;
        return ans;
    }
};