class Solution {
public:
    int minimumLength(string s) 
    {
        map<char, int> mp;
        for(char ch:s) mp[ch]++;
        int ans = 0;
        for(auto [ch, cnt]:mp)
        {
            ans++;
            if(!(cnt%2)) ans++;
        }
        return ans;
    }
};