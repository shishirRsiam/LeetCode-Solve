class Solution:
    def minimumCost(self, nums: List[int]) -> int:
        def solve(i, cur):
            if not cur:
                return 0
            if i == len(nums):
                return 10 ** 10
            
            added = nums[i] + solve(i + 1, cur - 1)
            skip = solve(i + 1, cur)
            return min(added, skip)
        return nums[0] + solve(1, 2)