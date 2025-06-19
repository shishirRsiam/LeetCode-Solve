class Solution {
public:
    int partitionArray(vector<int>& nums, int k) 
    {
        sort(begin(nums), end(nums));

        int cur = 0, ans = 1, n = nums.size();
        for(int i = 0; i < n; i++)
            if(k < nums[i] - nums[cur]) 
                cur = i, ans += 1;

        return ans;
    }
};