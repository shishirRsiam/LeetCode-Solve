class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        ans = 0
        for val in nums:
            ans += not (len(str(val)) % 2)
        return ans