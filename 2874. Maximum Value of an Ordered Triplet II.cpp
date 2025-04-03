class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) 
    {
        int n = nums.size();
        int maxLeft = 0, maxRight = 0;
        vector<int>topLeft(n), topRight(n);
        for(int i = 0; i < n; i++)
        {
            topLeft[i] = maxLeft;
            topRight[n - i - 1] = maxRight;
            maxLeft = max(maxLeft, nums[i]);
            maxRight = max(maxRight, nums[n - i - 1]);
        }

        long ans = 0;
        for(int i = 0; i < n; i++)
        {
            long dif = topLeft[i] - nums[i];
            ans = max(ans, dif * topRight[i]);
        }
        return ans;
    }
};