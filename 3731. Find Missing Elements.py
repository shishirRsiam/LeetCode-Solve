class Solution:
    def findMissingElements(self, nums: List[int]) -> List[int]:
        ans = []
        max_val, min_val = max(nums), min(nums)
        for i in range(min_val, max_val):
            if i not in nums:
                ans.append(i)
        return ans