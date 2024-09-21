class Solution
{
public:
    int longestFirstPalindrome(const string &s)
    {
        int n = s.size(), j;
        vector<int> pi(n);
        for (int i = 1; i < n; i++)
        {
            j = pi[i - 1];
            while (j and s[i] != s[j])
                j = pi[j - 1];

            j += s[i] == s[j];
            pi[i] = j;
        }
        return pi[n - 1];
    }
    string shortestPalindrome(string s)
    {
        string reserse_s = s;
        reverse(begin(reserse_s), end(reserse_s));

        string combine = s + "&" + reserse_s;
        int longestSize = longestFirstPalindrome(combine);

        string addMore;
        int n = s.size();
        for (int i = longestSize; i < n; i++)
            addMore += s[i];
        reverse(begin(addMore), end(addMore));

        return addMore + s;
    }
};