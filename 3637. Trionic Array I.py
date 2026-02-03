class Solution:
    def isTrionic(self, nums: List[int]) -> bool:
        i, n = 0, len(nums)
        f1, f2, f3 = 0, 0, 0
        
        while i < n - 1 and nums[i] < nums[i + 1]:
            f1 = 1
            i += 1
        
        while i < n - 1 and nums[i] > nums[i + 1]:
            f2 = 1
            i += 1
        
        while i < n - 1 and nums[i] < nums[i + 1]:
            f3 = 1
            i += 1
        
        return bool(i == n - 1 and f1 and f2 and f3)