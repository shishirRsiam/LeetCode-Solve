class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int index = 0, cnt = 0, value = nums[0];

        for (auto val : nums)
        {
            if (value == val)
                cnt += 1;
            else
            {
                cnt = 1;
                value = val;
            }
            if (cnt <= 2)
                nums[index++] = val;
        }

        return index;
    }
};