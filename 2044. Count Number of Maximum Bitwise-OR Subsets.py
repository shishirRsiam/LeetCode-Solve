class Solution:
    def getOr(self, arr, Or=0):
        for num in arr:
            Or |= num
        return Or
    def countMaxOrSubsets(self, nums: List[int]) -> int:
        n = len(nums)
        maxOr = self.getOr(nums)
        def backtrack(i, cur):
            if i == n:
                return self.getOr(cur) == maxOr
            not_take = backtrack(i + 1, cur)
            take = backtrack(i + 1, cur + [nums[i]])
            return take + not_take
        return backtrack(0, [])