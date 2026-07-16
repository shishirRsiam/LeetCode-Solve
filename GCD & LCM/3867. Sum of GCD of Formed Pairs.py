class Solution:
    def gcdSum(self, nums: list[int]) -> int:
        store = []
        max_val = 0
        n = len(nums)
        for i in range(n):
            max_val = max(max_val, nums[i])
            store.append(gcd(nums[i], max_val))
        
        store.sort()
        target = n // 2
        return sum([gcd(store[i], store[n - i - 1]) for i in range(target)])

class Solution:
    def gcdSum(self, nums: list[int]) -> int:
        store = []
        max_val = 0
        for val in nums:
            max_val = max(max_val, val)
            store.append(gcd(val, max_val))
        
        i = 0
        ans = 0
        n = len(store)
        store.sort()
        while i < (n // 2):
            ans += gcd(store[i], store[n - i - 1])
            i += 1
        return ans