class Solution
{
public:
    int maximumStrongPairXor(vector<int> &nums)
    {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (abs(nums[i] - nums[j]) > min(nums[i], nums[j]))
                    continue;
                ans = max(ans, (nums[i] ^ nums[j]));
            }
        }
        return ans;
    }
};