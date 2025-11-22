class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        ans = 0
        for val in nums:
            if val % 3:
                ans += 1
        return ans