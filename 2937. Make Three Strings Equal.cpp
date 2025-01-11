class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) 
    {
        int allSizeSum = s1.size() + s2.size() + s3.size();
        int ans = allSizeSum, n = min({s1.size(), s2.size(), s3.size()});
        for(int i = 0; i < n; i++)
        {
            if(s1[i] == s2[i] and s1[i] == s3[i]) ans -= 3;
            else break;
        }
        return ans == allSizeSum ? -1 : ans;
    }
};