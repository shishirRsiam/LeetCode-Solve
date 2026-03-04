class Solution:
    def numSpecial(self, grid: List[List[int]]) -> int:
        row, col = [], []
        n, m = len(grid), len(grid[0])
        for i in range(n):
            row.append(grid[i].count(1))
        for j in range(m):
            count = 0
            for i in range(n):
                count += grid[i][j]
            col.append(count)
        
        ans = 0
        for i in range(n):
            for j in range(m):
                ans += grid[i][j] == 1 and row[i] == 1 and col[j] == 1
        return ans