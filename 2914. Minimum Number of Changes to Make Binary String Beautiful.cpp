class Solution {
public:
    int minChanges(string s) 
    {
        int ans = 0, n = s.size();
        for(int i = 0; i < n; i += 2)
            if(s[i] != s[i + 1]) 
                ans += 1;
        
        return ans;    
    }
};