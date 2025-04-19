class FindSumPairs {
public:
    vector<int> nums;
    unordered_map<int, int> storeCount, storeCount2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) 
    {
        nums = nums2;
        for(auto &val : nums1) storeCount[val] += 1;
        for(auto &val : nums2) storeCount2[val] += 1;
    }
    
    void add(int index, int val) 
    {
        storeCount2[nums[index]] -= 1;
        nums[index] += val;
        storeCount2[nums[index]] += 1;
    }
    
    int count(int tot) 
    {
        int ans = 0;
        for(auto [val, cnt] : storeCount2)
            ans += storeCount[tot - val] * cnt;
        return ans;
    }
};