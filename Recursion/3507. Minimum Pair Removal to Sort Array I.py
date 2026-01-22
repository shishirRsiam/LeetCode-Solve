class Solution:
    def minimumPairRemoval(self, nums: List[int]) -> int:
        if sorted(nums) == nums:
            return 0

        n = len(nums)
        min_val = min([nums[i] + nums[i + 1] for i in range(n - 1)])
        for i in range(n - 1):
            if nums[i] + nums[i + 1] == min_val:
                return 1 + self.minimumPairRemoval(nums[:i] + [min_val] + nums[i+2:])
        
        return -1 # Not Reached!