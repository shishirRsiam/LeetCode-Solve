class Solution(object):
    def missingRolls(self, rolls, mean, n):
        # m is the number of observed rolls
        m = len(rolls)
        
        # Calculate the sum of the observed rolls
        cur_sum = sum(rolls)
        
        # Step 1: Calculate the total sum required for all n + m rolls to have the given mean
        # required_sum is the sum that the n + m rolls should add up to
        required_sum = (n + m) * mean

        # Step 2: Calculate the sum that the missing n rolls should add up to
        # missing_sum is the difference between required_sum and cur_sum
        missing_sum = required_sum - cur_sum

        # Step 3: Check if it is possible to generate n missing rolls that sum to missing_sum
        # Each missing roll must be between 1 and 6, so the sum of n rolls must be between n and n*6
        if missing_sum < n or missing_sum > n * 6:
            return []  # If the missing_sum is not achievable, return an empty list

        # Step 4: Initialize an array of size n with all elements set to 1 (minimum value for each roll)
        ans = [1] * n

        # Subtract n from missing_sum since we initialized each roll with 1
        missing_sum -= n

        # Step 5: Distribute the remaining missing_sum across the n rolls
        for i in range(n):
            # Add as much as possible (at most 5, since each roll can be at most 6)
            ans[i] += min(5, missing_sum)

            # Decrease the remaining missing_sum by the amount added to ans[i]
            missing_sum -= 5

            # If missing_sum is now zero, break out of the loop as no more distribution is needed
            if missing_sum <= 0:
                break

        # Return the constructed array of missing rolls
        return ans