var minOperationsToMakeMedianK = function(nums, k) {
    // Initialize a variable to count the total operations needed
    let ans = 0;

    // Sort the nums array in ascending order
    nums.sort((a, b) => a - b);

    // Get the length of the nums array
    let n = nums.length;

    // Calculate the index of the median
    let mid = Math.floor(n / 2);

    // Check if the current median is greater than k
    if (nums[mid] > k) {
        // If the median is greater than k, reduce values in the left half
        while (mid >= 0) {
            // Break the loop if the current value is less than or equal to k
            if (nums[mid] <= k) break;
            // Add the absolute difference between k and the current value to ans
            ans += Math.abs(k - nums[mid]);
            // Decrement mid to check the previous element
            mid--;
        }
    } else {
        // If the median is less than or equal to k, increase values in the right half
        while (mid < n) {
            // Break the loop if the current value is greater than or equal to k
            if (nums[mid] >= k) break;
            // Add the absolute difference between k and the current value to ans
            ans += Math.abs(k - nums[mid]);
            // Increment mid to check the next element
            mid++;
        }
    }

    // Return the total number of operations needed to make the median equal to k
    return ans;
};