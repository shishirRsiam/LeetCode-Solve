class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) 
    {
        vector<int> store;
        nums.push_back(-(1e9 + 5));
        
        int count = 1, n = nums.size();
        for(int i = 1; i < n; i++)
        {
            if(nums[i - 1] < nums[i]) count += 1;
            else
            {
                store.push_back(count);
                count = 1;
            }
        }

        int ans = 0;
        for(auto &val : store)
            ans = max(ans, (val / 2));
        
        n = store.size();
        for(int i = 1; i < n; i++)
            ans = max(ans, min(store[i - 1], store[i]));
        return ans;
    }
};