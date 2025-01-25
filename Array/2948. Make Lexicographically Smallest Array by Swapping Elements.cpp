class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) 
    {
        vector<int> ans = nums;
        sort(begin(nums), end(nums));

        int parent = 0, n = nums.size();
        unordered_map<int, int> valueParent;
        unordered_map<int, deque<int>> store;

        valueParent[nums[0]] = parent;
        store[parent].push_back(nums[0]);
        for(int i = 1; i < n; i++)
        {
            if((nums[i] - nums[i - 1]) > limit) parent += 1;

            valueParent[nums[i]] = parent;
            store[parent].push_back(nums[i]);
        }

        for(auto &val : ans)
        {
            parent = valueParent[val];
            val = store[parent].front();
            store[parent].pop_front();
        }
        return ans;
    }
};