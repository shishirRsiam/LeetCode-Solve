class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        sort(begin(nums), end(nums));
        int ans = 0, i = 0, j = nums.size() - 1;
        while (i < j)
        {
            if (nums[i] + nums[j] == k)
            {
                ans += 1;
                i += 1, j -= 1;
            }
            else if (nums[i] + nums[j] > k)
                j--;
            else if (nums[i] + nums[j] < k)
                i++;
        }
        return ans;
    }
};