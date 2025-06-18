class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) 
    {
        vector<vector<int>> ans;
        sort(begin(nums), end(nums));

        int n = nums.size();
        for(int i = 0; i < n; i += 3)
        {
            if(k < nums[i + 2] - nums[i])
                return {};
            ans.push_back({nums[i], nums[i + 1], nums[i + 2]});
        }
        return ans;
    }
};