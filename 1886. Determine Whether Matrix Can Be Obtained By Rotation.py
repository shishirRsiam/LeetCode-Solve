class Solution:
    def findRotation(self, mat: List[List[int]], target: List[List[int]]) -> bool:
        def roted_90(grid):
            n = len(grid)
            for i in range(n):
                for j in range(i, n):
                    grid[i][j], grid[j][i] = grid[j][i], grid[i][j]
            for i in range(n):
                grid[i].reverse()
            return grid == target
        
        n = len(mat)
        for _ in range(n * n):
            if roted_90(mat):
                break
        return mat == target