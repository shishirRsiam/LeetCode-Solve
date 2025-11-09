class Solution:
    def minMoves(self, nums: List[int]) -> int:
        ans = 0
        max_element = max(nums)
        for val in nums:
            ans += max_element - val
        return ans