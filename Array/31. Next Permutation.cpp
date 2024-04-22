class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        if(nums.size()==1) return;
        if(nums.size()==2)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        if(nums[0]>nums[1])
        {
            vector<int>tmp = nums;
            sort(tmp.rbegin(), tmp.rend());
            if(tmp==nums)
            {
                sort(nums.begin(), nums.end());
                return;
            }
        }
        vector<vector<int>>ans;
        do 
        {
            if(ans.size() == 2) break;
            ans.push_back(nums);
        }
        while(next_permutation(nums.begin(), nums.end()));
        nums = ans[1];
        return;
    }
};