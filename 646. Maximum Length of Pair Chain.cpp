class cmp
{
public:
    bool operator()(auto &a, auto &b)
    {
        return a[1] < b[1];
    }
};
class Solution
{
public:
    int findLongestChain(vector<vector<int>> &pairs)
    {
        sort(begin(pairs), end(pairs), cmp());

        int ans = 1;
        vector<int> prev = pairs[0];
        for (auto vec : pairs)
        {
            if (prev[1] < vec[0])
            {
                ans += 1;
                prev = vec;
            }
        }
        return ans;
    }
};