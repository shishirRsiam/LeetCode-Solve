class Solution {
public:
    int minCost(string c, vector<int>& nt) 
    {
        int n = c.size();
        int ans = 0, prev = 0;
        for(int i = 1; i < n; i++)
        {
            if(c[prev] != c[i]) prev = i;
            else 
            {
                if(nt[prev] < nt[i])
                {
                    ans += nt[prev];
                    prev = i;
                }
                else ans += nt[i];
            }
        }
        return ans;
    }
};