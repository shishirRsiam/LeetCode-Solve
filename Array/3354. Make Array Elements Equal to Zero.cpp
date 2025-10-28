class Solution {
public:
    int countValidSelections(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> prefix_sum = {nums[0]};
        for(int i = 1; i < n; i++)
            prefix_sum.push_back(prefix_sum.back() + nums[i]);
        if(prefix_sum.back() == 0)  return n * 2;

        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(not nums[i])
            {
                int dif = abs((prefix_sum.back() - prefix_sum[i]) - prefix_sum[i]);
                if(dif == 0) ans += 2;
                else if(dif == 1) ans += 1;
            }
        }
        return ans;
    }
};