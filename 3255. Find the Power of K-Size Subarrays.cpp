class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        // If k is 1, simply return the original array as each element is its own consecutive sequence
        if (k == 1) return nums;

        // Initialize a vector to store the results
        vector<int> ans;

        // Get the size of the input array
        int n = nums.size();
        
        // Initialize variables to track the current index and consecutive size
        int i = 1, consecutiveSize = 1;

        // Iterate through the array starting from the second element
        while (i < n) {
            // Check if the current element is consecutive to the previous one
            if (nums[i] - 1 == nums[i - 1]) {
                // If consecutive, increment the consecutive size
                consecutiveSize += 1;
            } 
            else {
                // If not consecutive, reset the consecutive size to 1
                consecutiveSize = 1;
            }

            // If we have processed at least k elements
            if (i >= k - 1) 
            {
                // Check if the length of consecutive elements is at least k
                // If true, add the current element to the results; otherwise, add -1
                ans.push_back(consecutiveSize >= k ? nums[i] : -1);
            }
            // Move to the next index
            i += 1;
        }
        // Return the results array
        return ans;
    }
};