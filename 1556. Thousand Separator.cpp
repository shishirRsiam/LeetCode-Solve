class Solution
{
public:
    string thousandSeparator(int n)
    {
        int count = 0;
        string ans, s = to_string(n);
        reverse(begin(s), end(s));
        for (auto ch : s)
        {
            if (not(count % 3))
                ans += '.';
            ans += ch;
            count++;
        }
        reverse(begin(ans), end(ans));
        ans.pop_back();
        return ans;
    }
};