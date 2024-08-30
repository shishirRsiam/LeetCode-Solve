class Solution(object):
    def minOperationsToMakeMedianK(self, nums, k):
        # Initialize the total number of operations needed to 0
        ans = 0
        
        # Get the number of elements in the list
        n = len(nums)
        
        # Calculate the index of the median
        mid = n // 2
        
        # Sort the list to facilitate median manipulation
        nums.sort()
        
        # Check if the current median is greater than k
        if nums[mid] > k:
            # If the median is greater than k, we need to reduce the values
            # to make the median equal to k
            while mid >= 0:
                # Stop if we encounter a value less than or equal to k
                if nums[mid] <= k: break
                # Add the absolute difference between the current number and k
                # to the total operations
                ans += abs(k - nums[mid])
                # Move to the previous element
                mid -= 1
        else:
            # If the median is less than or equal to k, we need to increase
            # the values to make the median equal to k
            while mid < n:
                # Stop if we encounter a value greater than or equal to k
                if nums[mid] >= k: break
                # Add the absolute difference between the current number and k
                # to the total operations
                ans += abs(k - nums[mid])
                # Move to the next element
                mid += 1
        
        # Return the total number of operations needed to make the median equal to k
        return ans