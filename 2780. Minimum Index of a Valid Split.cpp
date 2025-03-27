class Solution {
    public:
        int minimumIndex(vector<int>& nums) 
        {
            unordered_map<int, int> store;
            int dominantVal = -1, dominantValCount = 0, n = nums.size();
            for(int i = 0; i < n; i++)
            {
                store[nums[i]] += 1;
                if(store[nums[i]] * 2 > n) dominantVal = nums[i]; 
            }
    
            for(int i = 0; i < n; i++)
            {
                dominantValCount += nums[i] == dominantVal;
                if(dominantValCount * 2 > i + 1 and ((store[dominantVal] - dominantValCount) * 2 > (n - i - 1)))
                    return i;
            }
            return -1;
        }
    };