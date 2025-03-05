class Solution:
    def coloredCells(self, n: int) -> int:
        ans, color = 1, 4
        for i in range(1, n):
            ans += color
            color += 4
        return ans