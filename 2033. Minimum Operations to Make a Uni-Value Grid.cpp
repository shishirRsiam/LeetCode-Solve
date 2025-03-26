class Solution {
    public:
        int minOperations(vector<vector<int>>& grid, int x) 
        {
            vector<int> nums;
            for(auto &vec : grid)
                for(auto &val : vec) 
                    nums.push_back(val);
            sort(begin(nums), end(nums));
            
            int ans = 0, mid = nums[nums.size() / 2], need;
            for(auto &val : nums)
            {
                need = abs(mid - val);
                if(need % x) return -1;
                ans += need / x;
            }
            return ans;
        }
    };