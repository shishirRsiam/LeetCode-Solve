class Solution
{
public:
    void Operation(vector<int> nums, int &ans)
    {
        string bits;
        for (auto val : nums)
        {
            bitset<32> bit(val);
            bool flag = false;
            for (int i = 31; i >= 0; i--)
            {
                if (bit[i])
                    flag = true;
                if (flag)
                    bits += to_string(bit[i]);
            }
        }
        ans = max(ans, stoi(bits, NULL, 2));
    }
    int maxGoodNumber(vector<int> &nums)
    {
        int ans = 0;
        Operation(nums, ans);
        Operation({nums[0], nums[2], nums[1]}, ans);
        Operation({nums[1], nums[0], nums[2]}, ans);
        Operation({nums[1], nums[2], nums[0]}, ans);
        Operation({nums[2], nums[1], nums[0]}, ans);
        Operation({nums[2], nums[0], nums[1]}, ans);
        return ans;
    }
};