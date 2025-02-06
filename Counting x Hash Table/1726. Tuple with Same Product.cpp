class Solution {
public:
    int tupleSameProduct(vector<int>& nums) 
    {
        int ans = 0, n = nums.size();
        unordered_map<long, int> store;
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                store[long(nums[i]) * nums[j]] += 1;

        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                ans += (store[long(nums[i]) * nums[j]] - 1) * 4;

        return ans; 
    }
};