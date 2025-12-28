class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        ans = 0
        for arr in grid:
            for val in arr[::-1]:
                if val >= 0: break
                ans += 1
        return ans