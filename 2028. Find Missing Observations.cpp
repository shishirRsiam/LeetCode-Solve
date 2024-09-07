class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) 
    {
        // Number of observed rolls (m)
        int m = rolls.size();
        
        // Step 1: Calculate the total sum required for all n + m rolls to have the given mean
        long required_sum = (n + m) * mean;

        // Step 2: Calculate the sum of the observed rolls
        long sum = accumulate(begin(rolls), end(rolls), 0);

        // Step 3: Calculate the sum that the missing n rolls should add up to
        long missing_sum = required_sum - sum;

        // Step 4: Check if it is possible to generate n missing rolls that sum to missing_sum
        // Each missing roll must be between 1 and 6, so the sum of n rolls must be between n and n*6
        if (missing_sum < n || missing_sum > n * 6) return {};  // If impossible, return an empty array

        // Step 5: Initialize an array of size n with all elements set to 1 (minimum value for each roll)
        vector<int> ans(n, 1);

        // Subtract n from missing_sum since we initialized the n rolls with 1's
        missing_sum -= n;

        // Step 6: Distribute the remaining missing_sum across the n rolls
        for (int i = 0; i < n; i++)
        {
            // Add as much as possible (at most 5, since each roll can be at most 6)
            ans[i] += min(long(5), missing_sum);
            
            // Decrease the remaining missing_sum by the amount added to ans[i]
            missing_sum -= min(long(5), missing_sum);

            // If missing_sum is now zero, break out of the loop as no more distribution is needed
            if (missing_sum <= 0) break;
        }
        
        // Return the constructed array of missing rolls
        return ans;
    }
};