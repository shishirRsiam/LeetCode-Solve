class Solution:
    def missingMultiple(self, nums: List[int], k: int) -> int:
        missing = k
        nums = set(nums)
        while missing in nums:
            missing += k
        return missing
