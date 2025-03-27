class Solution {
    public:
        int partitionDisjoint(vector<int>& nums) 
        {
            int n = nums.size();
            vector<int> left(n), right(n); 
            int minVal = nums[n - 1], maxVal = nums[0];
            
            for(int i = 0; i < n; i++)
            {
                left[i] = maxVal;
                maxVal = max(maxVal, nums[i]);
            }
    
            for(int i = n - 1; i >= 0; i--)
            {
                right[i] = minVal;
                minVal = min(minVal, nums[i]);
            }
    
            for(int i = 0; i < n - 1; i++)
                if(left[i] <= right[i]) return i + 1;
            return -1;
        }
    };