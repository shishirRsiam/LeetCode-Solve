class Solution:
    def maxAlternatingSum(self, nums: List[int]) -> int:
        ans = 0
        n = len(nums)
        i, j = 0, n - 1

        nums = [abs(x) for x in nums]
        nums.sort()

        while i < j:
            ans += nums[j] * nums[j]
            ans -= nums[i] * nums[i]
            i += 1
            j -= 1

        if i == j:
            ans += nums[i] * nums[i]
            
        return ans
        