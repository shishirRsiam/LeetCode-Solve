class Solution {
    public:
        vector<int> applyOperations(vector<int>& nums) 
        {
            int n = nums.size();
            for(int i=0;i<n-1;i++)
            {
                if(nums[i]==nums[i+1])
                {
                    nums[i++] *= 2;
                    nums[i] = 0;
                }
            }
    
            vector<int>ans;
            for(int v:nums)
                if(v) ans.push_back(v);
            
            int zero = count(nums.begin(), nums.end(), 0);
            while(zero--) ans.push_back(0);
    
            return ans;
        }
    };