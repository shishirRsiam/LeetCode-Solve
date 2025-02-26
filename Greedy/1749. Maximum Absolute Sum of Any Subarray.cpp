class Solution {
    public:
        int maxAbsoluteSum(vector<int>& nums) 
        {
            int sum = 0, ans = INT_MIN;
            for(auto &val : nums)
            {
                sum += val;
                if(sum < 0) sum = 0;
                ans = max(ans, abs(sum));
            }
    
            sum = 0;
            for(auto &val : nums)
            {
                sum += val;
                if(sum < 0) ans = max(ans, abs(sum));
                else sum = 0;
            }
            return ans;
        }
    };