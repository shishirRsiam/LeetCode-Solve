class Solution:
    def zeroFilledSubarray(self, nums: List[int]) -> int:
        ans, count = 0, 0
        for val in nums:
            if val:
                count = 0
            else:
                count += 1
            ans += count
        return ans