class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        nums.sort()

        ans, i, j = 0, 0, len(nums) - 1
        while i < j:
            if nums[i] + nums[j] == k:
                ans += 1
                i += 1
                j -= 1
            elif nums[i] + nums[j] > k:
                j -= 1
            elif nums[i] + nums[j] < k:
                i += 1
        return ans