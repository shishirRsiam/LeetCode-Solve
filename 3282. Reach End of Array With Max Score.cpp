class Solution {
public:
    long long findMaximumScore(vector<int>& nums) 
    {
        long long ans = 0;  // This variable will store the final maximum score.
        int j = 0;  // 'j' will track the index of the current maximum element found so far.
        int n = nums.size();  // 'n' is the size of the input array 'nums'.
        
        // Iterate through the array 'nums'
        for(int i = 0; i < n; i++)
        {
            // Check if the current element is greater than the element at index 'j'
            if(nums[i] > nums[j])
            {
                // If a greater element is found, add the product of the current max element (nums[j])
                // and the distance between 'i' and 'j' to the result.
                ans += (long(nums[j]) * abs(i - j));
                
                // Update 'j' to 'i', as 'nums[i]' is now the new max element.
                j = i;
            }
        }
        
        // After the loop, add the remaining product of the final max element (nums[j])
        // and the distance from 'j' to the end of the array (n - j - 1).
        ans += (long(nums[j]) * (n - j - 1));
        
        // Return the final calculated maximum score.
        return ans;   
    }
};