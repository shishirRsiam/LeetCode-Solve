class Solution:
    def dominantIndices(self, nums: List[int]) -> int:
        ans, n = 0, len(nums)
        for i in range(n - 1):
            ans += nums[i] > (sum(nums[i+1:]) / (n - i - 1))
        return ans