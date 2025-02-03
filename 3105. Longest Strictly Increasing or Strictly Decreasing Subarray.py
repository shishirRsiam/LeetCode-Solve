class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
        ans, count, n = 1, 1, len(nums)
        for i in range(1, n):
            if nums[i] <= nums[i - 1]:
                count = 0
            count += 1
            ans = max(ans, count)

        count = 1
        for i in range(1, n):
            if nums[i] >= nums[i - 1]:
                count = 0
            count += 1
            ans = max(ans, count)

        return ans