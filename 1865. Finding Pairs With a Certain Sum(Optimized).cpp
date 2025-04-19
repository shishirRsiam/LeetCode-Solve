class FindSumPairs {
public:
    vector<int> nums, numss;
    unordered_map<int, int> storeCount;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) 
    {
        nums = nums1, numss = nums2;
        for(auto &val : numss) storeCount[val] += 1;
    }
    
    void add(int index, int val) 
    {
        storeCount[numss[index]] -= 1;
        numss[index] += val;
        storeCount[numss[index]] += 1;
    }
    
    int count(int tot) 
    {
        int ans = 0;
        for(auto val : nums)
            ans += storeCount[tot - val] * 1;
        return ans;
    }
};