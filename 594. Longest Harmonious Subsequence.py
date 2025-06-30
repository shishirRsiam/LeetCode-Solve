class Solution:
    def findLHS(self, nums: List[int]) -> int:
        ans = 0
        count = Counter(nums)
        for val in count:
            prev = val - 1
            if prev in count:
                ans = max(ans, count[val] + count[prev])
        return ans