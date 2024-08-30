var resultsArray = function(nums, k) {
    // Initialize an array to store the results
    let ans = [];
    
    // Initialize index variable i, get the length of nums, and set consecutiveSize to 1
    let i = 0, n = nums.length, consecutiveSize = 1;
    
    // If the input array has only one element, return it directly
    if (n == 1) return nums;

    // Iterate through the nums array
    while (i < n) {
        // Check if the current element is consecutive to the previous one
        if (nums[i] - 1 == nums[i - 1]) {
            // If they are consecutive, increment the consecutive size
            consecutiveSize += 1;
        } else {
            // If not, reset consecutive size to 1
            consecutiveSize = 1;
        }
        
        // If we have processed at least k elements
        if (i >= k - 1) {
            // Check if the length of consecutive elements is at least k
            if (consecutiveSize >= k) {
                // If true, add the current element to the results
                ans.push(nums[i]);
            } else {
                // If false, add -1 to indicate no valid consecutive sequence
                ans.push(-1);
            }
        }
        // Move to the next index
        i++;
    }
    // Return the results array
    return ans;
};