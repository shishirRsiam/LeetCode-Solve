class Solution {
    public:
        int numberOfSubstrings(string s) 
        {
            int n = s.size(), ans = 0;
            vector<int> lastSeen(100);
            for(int i = 0; i <= n; i++)
            {
                ans += min({lastSeen['a'], lastSeen['b'], lastSeen['c']});
                lastSeen[s[i]] = i + 1;
            }    
            return ans;
        }
    };