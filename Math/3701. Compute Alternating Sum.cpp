class Solution {
public:
    int alternatingSum(vector<int>& nums) 
    {
        bool flag = true;
        int ans = 0, n = nums.size();
        for(int i = 0; i < n; i++)
        {
            ans += flag ? nums[i] : -nums[i];
            flag = not flag;
        }
        return ans;
    }
};