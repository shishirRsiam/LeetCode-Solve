class Solution:
    def countFairPairs(self, nums: List[int], lower: int, upper: int) -> int:
        ans = 0
        nums.sort()
        pbds = SortedList()
        for val in nums:
            min_val, max_val = lower - val, upper - val
            ans += pbds.bisect_right(max_val) - pbds.bisect_left(min_val)
            pbds.add(val)
        return ans