class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        int count = 0, ans = 0;

        for (auto ch : s)
        {
            if (ch == '(')
                count++;
            else
                count ? count-- : ans++;
        }

        return ans + count;
    }
};