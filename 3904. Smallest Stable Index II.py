class Solution:
    def firstStableIndex(self, nums: list[int], k: int) -> int:
        n = len(nums)
        MAX = 10 ** 10
        left, right = [-MAX] * n, [MAX] * n

        left[0] = nums[0]
        right[n - 1] = nums[n - 1]

        for i in range(1, n):
            left[i] = max(left[i - 1], nums[i])
        for i in range(n - 2, -1, -1):
            right[i] = min(right[i + 1], nums[i])

        for i in range(n):
            dif = left[i] - right[i]
            if dif >= 0 and dif <= k:
                return i
        return -1
 