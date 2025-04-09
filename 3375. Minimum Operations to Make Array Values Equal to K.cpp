class Solution {
public:
    int minOperations(vector<int>& nums, int k) 
    {
        unordered_map<int, int> store;
        for(auto &val : nums)
        {
            if(val < k) return -1;
            store[val] += 1;
        }
        
        int ans = 0;
        for(auto [val, count] : store)
        {
            if(val == k) continue;
            ans += 1;
        }
        return ans;    
    }
};