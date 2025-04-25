class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int targetRemainder) 
    {
        int n = nums.size();
        long long matchedPrefixSum = 0;
        long long totalInterestingSubarrays = 0;
        unordered_map<int, long long> remainderCountMap;

        remainderCountMap[0] = 1;
        for(int i = 0; i < n; i++) 
        {
            if(nums[i] % modulo == targetRemainder)
                matchedPrefixSum += 1;

            int currentRemainder = matchedPrefixSum % modulo;
            int requiredRemainder = (currentRemainder - targetRemainder + modulo) % modulo;

            totalInterestingSubarrays += remainderCountMap[requiredRemainder];
            remainderCountMap[currentRemainder]++;
        }

        return totalInterestingSubarrays;
    }
};