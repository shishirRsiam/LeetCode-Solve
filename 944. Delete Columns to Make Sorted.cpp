class Solution {
public:
    int minDeletionSize(vector<string>& str) 
    {
        map<int,string>mp;
        int i = 0, n = str[0].size();
        while(i<n)
        {
            for(auto s:str)
                mp[i] += (s[i]);
            i++;
        }

        int ans = 0;
        for(auto [val, s]:mp)
        {
            string temp = s;
            sort(temp.begin(), temp.end());
            if(temp != s) ans++;
        }
        return ans;
    }
};