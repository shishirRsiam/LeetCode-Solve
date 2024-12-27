class Solution {
public:
    int minimumOperations(vector<int>& nums) 
    {
        int ans = 0, n = nums.size();
        unordered_map<int, int> count;
        for(int i = n - 1; i >= 0; i--)
        {
            if(count[nums[i]]) break;
            count[nums[i]]++;
        }
        return ceil((n - count.size()) / 3.0);
    }
};