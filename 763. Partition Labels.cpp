class Solution {
public:
    vector<int> partitionLabels(string s) 
    {
        map<char,int>mp;
        mp[NULL] = INT_MAX;
        int n = s.size();
        for(int i=0;i<n;i++) mp[s[i]] = i;
        
        vector<int>ans;
        int cur = -1, i = 0, mx = mp[s[0]];
        while(mx < n)
        {
            while(i <= mx)
                mx = max(mx, mp[s[i++]]);
            ans.push_back(mx - cur);
            cur = mx;
            mx = mp[s[i]];
        }
        return ans;
    }
};