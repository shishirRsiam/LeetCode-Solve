class Solution:
    def countSubmatrices(self, grid: List[List[int]], k: int) -> int:
        n, m = len(grid), len(grid[0])

        for i in range(n):
            for j in range(1, m):
                grid[i][j] += grid[i][j - 1]

        for i in range(1, n):
            for j in range(m):
                grid[i][j] += grid[i - 1][j]
        
        
        ans = 0
        for nums in grid:
            for val in nums:
                ans += val <= k
        return ans