class Solution {
    public:
        long long countBadPairs(vector<int>& nums) 
        {
            int n = nums.size();
            unordered_map<int, int> store;  
            long ans = (n * long(n - 1)) / 2;
            for(int i = n - 1; i >= 0; i--)
            {
                ans -= store[nums[i] - i];
                store[nums[i] - i] += 1;
            }
            return ans;  
        }
    };