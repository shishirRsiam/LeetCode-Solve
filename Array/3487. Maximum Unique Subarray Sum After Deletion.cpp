class Solution {
public:
    int maxSum(vector<int>& nums) 
    {
        unordered_set<int> unique_nums;
        for(auto &val : nums)
            unique_nums.insert(val);

        int ans = 0, max_val_in_nums = INT_MIN;
        for(auto &val : unique_nums)
        {
            if(val > 0) ans += val;
            max_val_in_nums = max(max_val_in_nums, val);
        }
        return ans ? ans : max_val_in_nums;    
    }
};