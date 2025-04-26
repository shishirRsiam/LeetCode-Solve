class Solution:
    def countSubarrays(self, nums: List[int], minK: int, maxK: int) -> int:
        minpos, maxpos, unbound = -1, -1, -1

        ans, n = 0, len(nums)
        for i in range(n):
            if nums[i] < minK or nums[i] > maxK:
                unbound = i
            if nums[i] == minK:
                minpos = i
            if nums[i] == maxK:
                maxpos = i
            
            canadd = min(minpos, maxpos) - unbound
            if canadd > 0:
                ans += canadd

        return ans 