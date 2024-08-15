class Solution {
public:
    int alternateDigitSum(int n) 
    {
        string s = to_string(n);
        int ans = 0, flag = true, val;
        for(char ch:s)
        {
            val = ch - '0';
            ans += (flag ? val : -val);
            flag = !flag;
        }    
        return ans;
    }
};