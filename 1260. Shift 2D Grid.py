class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        n, m = len(grid), len(grid[0])

        for _ in range(k):
            cur = grid[-1][-1]

            for i in range(n):
                for j in range(m):
                    cur, grid[i][j] = grid[i][j], cur
        
        return grid