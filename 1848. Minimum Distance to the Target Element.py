class Solution:
    def getMinDistance(self, nums: List[int], target: int, start: int) -> int:
        n, ans = len(nums), 10 ** 10
        for i in range(n):
            if nums[i] == target:
                ans = min(ans, abs(i - start))
        return ans