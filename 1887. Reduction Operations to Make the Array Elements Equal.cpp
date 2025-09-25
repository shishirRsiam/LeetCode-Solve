class Solution {
public:
    int reductionOperations(vector<int>& nums) 
    {
        int ans = 0;
        unordered_set<int> store;
        sort(begin(nums), end(nums));
        for(auto &val : nums)
        {
            store.insert(val);
            ans += (store.size() - 1);
        }
        return ans;
    }
};