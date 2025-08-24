class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        nums.append(0)
        ans, count, prev, n = 0, 0, 0, len(nums)
        for val in nums:
            count += val
            if not val:
                ans = max(ans, count + prev)
                prev, count = count, 0            
        ans -= ans == n - 1
        return ans