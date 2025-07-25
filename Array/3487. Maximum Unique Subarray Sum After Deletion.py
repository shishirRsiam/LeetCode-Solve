class Solution:
    def maxSum(self, nums: List[int]) -> int:
        ans = 0
        added = set()
        for num in nums:
            if num > 0 and num not in added:
                ans += num
                added.add(num)
        return ans if ans else max(nums)