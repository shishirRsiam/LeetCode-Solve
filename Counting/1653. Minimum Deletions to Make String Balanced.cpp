class Solution {
public:
    int minimumDeletions(string s) 
    {
        int ans = 0, countB = 0;
        for(auto ch:s)
        {
            if(ch == 'a') ans = min(ans+1, countB);
            else countB++;
        }
        return ans;
    }
};