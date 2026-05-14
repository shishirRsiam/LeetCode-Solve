class Solution:
    def isGood(self, nums: List[int]) -> bool:
        nums.sort()
        n = len(nums)
        for i in range(1, n):
            if nums[i - 1] != i:
                return False
        return n > 1 and nums[-1] == nums[-2] == n - 1
