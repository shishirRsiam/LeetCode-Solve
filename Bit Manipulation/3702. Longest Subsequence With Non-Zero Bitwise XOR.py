class Solution:
    def longestSubsequence(self, nums: List[int]) -> int:
        st = set(nums)
        if len(st) == 1 and 0 in st:
            return 0
        XOR = 0
        for val in nums:
            XOR ^= val
        return len(nums) - (not bool(XOR))