class Solution
{
public:
    long long minimumSteps(string s)
    {
        long long ans = 0, one = 0;
        for (char ch : s)
            ch == '1' ? one++ : ans += one;
        return ans;
    }
};