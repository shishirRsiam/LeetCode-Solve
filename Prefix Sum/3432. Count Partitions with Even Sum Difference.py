class Solution:
    def countPartitions(self, nums: List[int]) -> int:
        ans = 0
        left_sum, right_sum = 0, sum(nums)
        for val in nums:
            left_sum += val
            right_sum -= val
            ans += not (left_sum -right_sum) % 2
        return max(0, ans - 1)