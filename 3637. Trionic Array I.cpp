class Solution {
public:
    bool isTrionic(vector<int>& nums) 
    {
        int i = 0, n = nums.size();
        bool flag1 = false, flag2 = false, flag3 = false;
        while(i < n - 1 and nums[i] < nums[i + 1]) flag1 = true; i++;            
        while(i < n - 1 and nums[i] > nums[i + 1]) flag2 = true; i++;
        while(i < n - 1 and nums[i] < nums[i + 1]) flag3 = true; i++;
        return i == n - 1 and flag1 and flag2 and flag3;
    }
};