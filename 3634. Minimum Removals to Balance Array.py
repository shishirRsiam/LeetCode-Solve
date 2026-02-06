class Solution:
    def minRemoval(self, nums: List[int], k: int) -> int:
        nums.sort()

        ans = 10**10
        i, j, n = 0, 0, len(nums)
        while j < n:
            while j < n and nums[j] <= nums[i] * k:
                j += 1
            ans = min(ans, n - (j - i))
            i += 1
        return ans