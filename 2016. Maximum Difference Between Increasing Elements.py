class Solution:
    def maximumDifference(self, nums: List[int]) -> int:
        ans, maxValue, n = 0, 0, len(nums)
        
        maxArr = [0] * n
        for i in range(n):
            maxArr[n - i - 1] = maxValue
            maxValue = max(maxValue, nums[n - i - 1])

        for i in range(n):
            ans = max(ans, maxArr[i] - nums[i])
        return ans if ans else -1