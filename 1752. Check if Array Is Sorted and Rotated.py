class Solution:
    def check(self, nums: List[int]) -> bool:
        flag = False
        n = len(nums)
        for i in range(1, n):
            if nums[i] < nums[i - 1]:
                arr = nums[i:] + nums[:i]
                nums.sort()
                return nums == arr
        return True