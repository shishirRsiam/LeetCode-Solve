class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        i, j, sum = 0, 0, 0
        ans, n = 0, len(nums)
        while j < n:
            sum += nums[j]
            while (j - i + 1) * sum >= k:
                sum -= nums[i]
                i += 1
            ans += j - i + 1
            j += 1
        return ans