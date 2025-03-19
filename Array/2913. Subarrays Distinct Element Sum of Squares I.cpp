class Solution {
    public:
        int sumCounts(vector<int>& nums) 
        {
            int ans = 0, n = nums.size();
            for(int i = 0; i < n; i++)
            {
                for(int j = i; j < n; j++)
                {
                    unordered_set<int> store;
                    for(int k = i; k <= j; k++)
                    {
                        store.insert(nums[k]);
                    }
                    ans += store.size() * store.size();
                }
            }
            return ans;    
        }
    };