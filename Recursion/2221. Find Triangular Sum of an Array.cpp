class Solution {
public:
    int triangularSum(vector<int>& nums) 
    {
        int n = nums.size();
        if(n == 1) return nums.back() % 10;

        vector<int> new_arr;
        for(int i = 1; i < n; i++)
            new_arr.push_back((nums[i] + nums[i - 1]) % 10);
        return triangularSum(new_arr);
    }
};