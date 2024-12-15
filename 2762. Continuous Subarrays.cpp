class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) 
    {
        long ans = 0;
        multiset<int> ml;
        int n = nums.size(), i = 0, j = 0;

        while(j < n)
        {
            ml.insert(nums[j++]);
            while(2 < *ml.rbegin() - *ml.begin())
            {
                auto it = ml.find(nums[i++]);
                ml.erase(it);
            }
            ans += (j - i);
        }
        
        return ans;
    }
};