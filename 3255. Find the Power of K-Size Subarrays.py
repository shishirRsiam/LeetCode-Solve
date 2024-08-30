class Solution(object):
    def resultsArray(self, nums, k):
        # Get the length of the input array
        n = len(nums)

        # If k is 1, simply return the original array as each element is its own consecutive sequence
        if k == 1:
            return nums

        # Initialize a list to store the results
        ans = []
        
        # Initialize index variable i and consecutiveSize
        i, consecutiveSize = 1, 1
        
        # Iterate through the nums array starting from the second element
        while i < n:
            # Check if the current element is consecutive to the previous one
            if nums[i] - 1 == nums[i - 1]:
                # If they are consecutive, increment the consecutive size
                consecutiveSize += 1
            else:
                # If not consecutive, reset the consecutive size to 1
                consecutiveSize = 1
            
            # If we have processed at least k elements
            if i >= k - 1:
                # Check if the length of consecutive elements is at least k
                if consecutiveSize >= k:
                    # If true, add the current element to the results
                    ans.append(nums[i])
                else:
                    # If false, add -1 to indicate that there is no valid consecutive sequence
                    ans.append(-1)
            
            # Move to the next index
            i += 1
        
        # Return the results array
        return ans