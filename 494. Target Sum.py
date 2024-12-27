class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        dp = {}
        def recurtion(idx, cur_sum):
            if idx == len(nums):
                return 1 if cur_sum == target else 0
            if (idx, cur_sum) in dp:
                return dp[(idx, cur_sum)]

            add = recurtion(idx + 1, cur_sum + nums[idx])
            subtract = recurtion(idx + 1, cur_sum - nums[idx])
            dp[(idx, cur_sum)] = add + subtract
            return add + subtract
        return recurtion(0, 0)