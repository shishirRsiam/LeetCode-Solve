class Solution {
    public:
        int numberOfAlternatingGroups(vector<int>& nums, int k) 
        {
            int cnt = 0, ans = 0;
            int i = 0, j = 0, n = nums.size();
            for(int i=0;i<k;i++)
                nums.push_back(nums[i]);
    
            while(j<(n+k)-1)
            {
                if(nums[j++] == nums[j]) i = j-1;
                if(j-i >= k) ans++;
            }
            return ans;
        }
    };