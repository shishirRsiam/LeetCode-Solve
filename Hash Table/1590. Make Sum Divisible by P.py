class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        all_sum = sum(nums)
        target = all_sum % p
        if not target:
            return 0
        
        store = {0: -1}
        ans, cur_sum, n = len(nums), 0, len(nums)
        for i in range(n):
            cur_sum = (cur_sum + nums[i]) % p
            rem = (cur_sum - target) % p
            
            if rem in store:
                ans = min(ans, i - store[rem])
            store[cur_sum] = i

        if ans == n:
            ans = -1
        return ans