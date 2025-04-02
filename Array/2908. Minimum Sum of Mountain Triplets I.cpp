class Solution {
public:
    int minimumSum(vector<int>& nums) 
    {
        int ans = INT_MAX, n = nums.size();
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                for(int k = j + 1; k < n; k++)
                {
                    if(nums[i] < nums[j] and nums[k] < nums[j])
                    {
                        ans = min(ans, nums[i] + nums[j] + nums[k]);
                    }
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};