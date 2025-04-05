class Solution {
public:
    auto solve(int i, int Xor, vector<int>& nums)
    {
        if(i == nums.size()) return Xor;

        int pic = solve(i + 1, Xor ^ nums[i], nums);
        int not_pic = solve(i + 1, Xor, nums);
        return pic + not_pic;
    }
    int subsetXORSum(vector<int>& nums) 
    {
        return solve(0, 0, nums);
    }
};