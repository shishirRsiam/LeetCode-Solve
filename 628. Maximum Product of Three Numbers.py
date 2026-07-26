class Solution:
    def maximumProduct(self, nums: List[int]) -> int:
        nums.sort()

        op1 = nums[-1] * nums[-2] * nums[-3]
        op2 = nums[-1] * (nums[0] * nums[1])

        return max(op1, op2)