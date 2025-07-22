class Solution(object):
    def maximumUniqueSubarray(self, nums):
        seen = set()
        ans, sum, i, j, n = 0, 0, 0, 0, len(nums)
        while j < n:
            sum += nums[j]
            while nums[j] in seen:
                sum -= nums[i]
                seen.remove(nums[i])
                i += 1
            seen.add(nums[j])
            ans = max(ans, sum)
            j += 1
        return ans