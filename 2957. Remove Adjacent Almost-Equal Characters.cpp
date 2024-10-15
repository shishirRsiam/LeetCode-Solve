class Solution
{
public:
    int removeAlmostEqualCharacters(string s)
    {
        int ans = 0, n = s.size();

        for (int i = 1; i < n; i++)
        {
            if (s[i] == s[i - 1])
            {
                ans++, i++;
                cout << "s[i] == s[i - 1]";
            }
            else if (s[i - 1] + 1 == s[i])
            {
                ans++, i++;
                cout << "s[i - 1] + 1 == s[i]";
            }
            else if (s[i - 1] == s[i] + 1)
            {
                ans++, i++;
                cout << "s[i - 1] == s[i] + 1";
            }
            cout << endl;
        }

        return ans;
    }
};