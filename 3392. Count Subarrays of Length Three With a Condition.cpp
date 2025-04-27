class Solution {
public:
    int countSubarrays(vector<int>& nums) 
    {
        int ans = 0, n = nums.size();
        for(int i = 1; i < n - 1; i++)
        {
            int op1 = ceil(nums[i] / 2.0);
            int op2 = nums[i - 1] + nums[i + 1];
            int op3 = ceil((nums[i] + 1) / 2.0);
            ans += (op1 == op2 and op2 != op3);
        }
        return ans;
    }
};