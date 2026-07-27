class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        max_val = max(nums)
        count = Counter(nums)
        if count[max_val] > 1:
            return (max_val - 1) * (max_val - 1)

        nums.remove(max_val)
        return (max_val - 1) * (max(nums) - 1)
        