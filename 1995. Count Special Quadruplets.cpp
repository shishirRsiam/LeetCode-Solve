class Solution {
public:
    int countQuadruplets(vector<int>& nums) 
    {
        int ans = 0, n = nums.size(), sum;
        for(int i = 0; i < n ;i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                vector<int> store(301);
                for(int k = j + 1; k < n; k++) 
                    store[nums[k]] += 1;

                for(int k = j + 1; k < n; k++)
                {
                    sum = nums[i] + nums[j] + nums[k];
                    ans += store[sum];
                    store[nums[k]] -= 1;
                }
            }
        }
        return ans;
    }
};