class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int maxElement = *max_element(begin(nums), end(nums));

        int ans = 1, cnt = 0;
        for (auto val : nums)
        {
            if (val == maxElement)
                cnt += 1;
            else
                cnt = 0;
            ans = max(ans, cnt);
        }
        return ans;
    }
};