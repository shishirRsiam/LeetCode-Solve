class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) 
    {
        int n = nums.size();
        vector<pair<int, int>> vec;
        for(int i = 0; i < n; i++)
            vec.push_back({nums[i], i});

        unordered_set<int>store;
        sort(rbegin(vec), rend(vec));

        for(auto [val, idx] : vec)
        {
            if(!k--) break;
            store.insert(idx);
        }

        vector<int>ans;
        for(int i = 0; i < n; i++)
            if(store.count(i)) ans.push_back(nums[i]);

        return ans;
    }
};