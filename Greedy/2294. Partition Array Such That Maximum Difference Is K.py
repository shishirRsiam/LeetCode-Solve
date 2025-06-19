class Solution:
    def partitionArray(self, nums: List[int], k: int) -> int:
        nums.sort()
        cur, ans, n = 0, 1, len(nums)
        for i in range(n):
            if k < nums[i] - nums[cur]:
                cur = i
                ans += 1
        return ans