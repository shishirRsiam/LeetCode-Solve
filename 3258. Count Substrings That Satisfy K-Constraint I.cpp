class Solution {
public:
    int countKConstraintSubstrings(string s, int k) 
    {
        int ans = 0, n = s.size();
        for(int i = 0; i < n; i++)
        {
            for(int j = i; j < n; j++)
            {
                int zero = 0, one = 0;
                for(int k = i; k <= j; k++)
                {
                    s[k] == '1' ? one++ : zero++;
                    // cout<<s[k]<<" ";
                }
                ans += (one <= k or zero <= k);
                // cout<<endl;
            }
        }
        return ans;
    }
};