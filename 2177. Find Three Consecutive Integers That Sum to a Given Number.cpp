class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) 
    {
        string ans;
        int i = 0, j = 0;
        int n = s.size(), m = spaces.size();
        while(j < m)
        {
            if(i == spaces[j])
                ans += ' ', j++;
            ans += s[i++];
        }
        while(i < n) ans += s[i++];
        return ans;
    }
};