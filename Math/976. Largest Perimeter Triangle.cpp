class Solution {
public:
    int largestPerimeter(vector<int>& nums) 
    {
        int ans = 0, n = nums.size();
        sort(begin(nums), end(nums));
        for(int i = 1; i < n - 1; i++)
        {
            int a = nums[i - 1], b = nums[i], c = nums[i + 1];
            if(a + b > c)
                ans = max(ans, (a + b + c));
        }
        return ans;    
    }
};