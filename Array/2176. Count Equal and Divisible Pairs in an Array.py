class Solution:
    def countPairs(self, nums: List[int], k: int) -> int:
        ans, n = 0, len(nums)
        for i in range(n):
            for j in range(i + 1, n):
                ans += not (i * j) % k and nums[i] == nums[j] 
        return ans