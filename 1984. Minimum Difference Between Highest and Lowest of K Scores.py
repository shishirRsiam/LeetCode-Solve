class Solution:
    def minimumDifference(self, nums: List[int], k: int) -> int:
        nums.sort()
        return min([nums[i + k - 1] - nums[i] for i in range(len(nums) - k + 1)])


class Solution:
    def minimumDifference(self, nums: List[int], k: int) -> int:
        nums.sort()
        ans, n = 10**10, len(nums)
        for i in range(n - k + 1):
            ans = min(ans, nums[i + k - 1] - nums[i])
        return ans