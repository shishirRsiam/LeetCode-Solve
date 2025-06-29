class Solution:
    def numSubseq(self, nums: List[int], target: int) -> int:
        nums.sort()
        n, MOD = len(nums), 10**9 + 7
        
        power = [1] * n
        for i in range(1, n):
            power[i] = (power[i-1] * 2) % MOD
        
        ans, left, right = 0, 0, n - 1
        while left <= right:
            if nums[left] + nums[right] <= target:
                ans = (ans + power[right - left]) % MOD
                left += 1
            else:
                right -= 1
        return ans