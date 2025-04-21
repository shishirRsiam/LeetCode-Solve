class Solution {
public:
    int countHillValley(vector<int>& nums) 
    {
        int ans = 0, n = nums.size();
        
        vector<int> arr = {nums[0]};
        for(int i = 1; i < n; i++)
        {
            if(nums[i] != nums[i - 1])
                arr.push_back(nums[i]);
        }

        nums = arr;
        n = nums.size();
        for(int i = 1; i < n - 1; i++)
        {
            ans += (nums[i] > nums[i + 1] and nums[i] > nums[i - 1]);
            ans += (nums[i] < nums[i + 1] and nums[i] < nums[i - 1]);
        }
        return ans;
    }
};