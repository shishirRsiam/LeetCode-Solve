class Solution:
    def countHillValley(self, nums: List[int]) -> int:
        temp = [nums[0]]
        for i in range(1, len(nums)):
            if nums[i] != nums[i - 1]:
                temp.append(nums[i])
        nums = temp

        ans = 0
        for i in range(1, len(nums) - 1):
            ans += (nums[i - 1] < nums[i] and nums[i + 1] < nums[i])
            ans += (nums[i - 1] > nums[i] and nums[i + 1] > nums[i])
        return ans