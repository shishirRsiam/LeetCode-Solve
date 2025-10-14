class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) 
    {
        vector<int> store;
        nums.push_back(-1005);
        
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

        for(auto &val : store)
            if(val >= (k + k)) return true;
        
        n = store.size();
        for(int i = 1; i < n; i++)
            if(store[i - 1] >= k and store[i] >= k)
                return true;
        return false;
    }
};