class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        nums.sort()
        nums.reverse()
        
        n = len(nums)
        for i in range(1, n - 1):
            a, b, c = nums[i + 1], nums[i], nums[i - 1]
            if a + b > c:
                return a + b + c
        return 0