class Solution
{
public:
    int maxSum(vector<int> &nums)
    {
        unordered_map<int, vector<int>> mp;
        for (auto val : nums)
        {
            int mx = 0;
            string s = to_string(val);
            for (auto ch : s)
                mx = max(mx, ch - '0');
            mp[mx].push_back(val);
        }

        int ans = -1;
        for (auto [val, vec] : mp)
        {
            if (vec.size() > 1)
            {
                sort(vec.rbegin(), vec.rend());
                ans = max(ans, vec[0] + vec[1]);
            }
        }

        return ans;
    }
};