class Solution:
    def applyOperations(self, nums: List[int]) -> List[int]:
        for i in range(len(nums) - 1):
            if nums[i] == nums[i + 1]:
                nums[i + 1] = 0
                nums[i] *= 2

        ans = []
        count_zero = 0
        for num in nums:
            if num: ans.append(num)
            else: count_zero += 1
        
        while count_zero:
            ans.append(0)
            count_zero -= 1
        
        return ans