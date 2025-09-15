class Solution {
public:
    int getMul(char ch, int index)
    {
        index += 1;
        int degree = abs((ch - 'a') - 26);
        return degree * index;
    }
    int reverseDegree(string s) 
    {
        int ans = 0, n = s.size();
        for(int i = 0; i < n; i++)
            ans += getMul(s[i], i);
        return ans;
    }
};