class Solution
{
public:
    int maxOperations(vector<int> &nums)
    {
        int ans = 0, n = nums.size();
        if (n < 2)
            return ans;

        int sum = nums[0] + nums[1];
        deque<int> dq(begin(nums), end(nums));
        while (dq.size() > 1 and dq[0] + dq[1] == sum)
        {
            ans += 1;
            dq.pop_front();
            dq.pop_front();
        }
        return ans;
    }
};