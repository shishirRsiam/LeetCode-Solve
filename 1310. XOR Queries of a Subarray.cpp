class Solution
{
public:
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
    {
        int n = arr.size(), l, r;
        vector<int> pref(n + 1);
        pref[0] = 0;
        for (int i = 1; i <= n; i++)
            pref[i] = pref[i - 1] ^ arr[i - 1];

        vector<int> ans;
        for (auto &Q : queries)
        {
            l = Q[0], r = Q[1] + 1;
            ans.push_back(pref[r] ^ pref[l]);
        }
        return ans;
    }
};