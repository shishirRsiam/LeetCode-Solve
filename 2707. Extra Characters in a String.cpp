class Solution
{
public:
    int n;
    vector<int> dp;
    unordered_set<string> st;
    int solve(int idx, string &s)
    {
        if (idx == n)
            return 0;

        if (dp[idx] != -1)
            return dp[idx];

        string cur;
        int minimumExtra = n;
        for (int i = idx; i < n; i++)
        {
            cur += s[i];

            int nextExtra = solve(i + 1, s);
            int curExtra = (st.count(cur)) ? 0 : cur.size();

            minimumExtra = min(minimumExtra, curExtra + nextExtra);
        }
        return dp[idx] = minimumExtra;
    }
    int minExtraChar(string s, vector<string> &dictionary)
    {
        n = s.size();
        dp.resize(55, -1);
        for (auto &dict : dictionary)
            st.insert(dict);
        return solve(0, s);
    }
};