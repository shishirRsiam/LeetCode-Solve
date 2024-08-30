class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) 
    {
        // Variable to store the total number of operations needed
        long ans = 0;
        
        // Sort the input array to facilitate median calculation
        sort(begin(nums), end(nums));
        
        // Get the size of the array and the index of the median
        int n = nums.size(), mid = n / 2;
        
        // Check if the current median is greater than k
        if (nums[mid] > k)
        {
            // If the median is greater than k, we need to reduce the values 
            // to make the median equal to k
            for (int i = mid; i >= 0; i--)
            {
                // If we encounter a value less than or equal to k, break the loop
                if (nums[i] <= k) break;
                
                // Add the absolute difference between the current number and k 
                // to the total operations
                ans += abs(nums[i] - k);
            }
        }
        else 
        {
            // If the median is less than or equal to k, we need to increase 
            // the values to make the median equal to k
            for (int i = mid; i < n; i++)
            {
                // If we encounter a value greater than or equal to k, break the loop
                if (nums[i] >= k) break;
                
                // Add the absolute difference between the current number and k 
                // to the total operations
                ans += abs(nums[i] - k);
            }
        }
        
        // Return the total number of operations needed to make the median equal to k
        return ans;
    }
};