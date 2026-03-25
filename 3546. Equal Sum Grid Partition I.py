class Solution:
    def canPartitionGrid(self, grid: List[List[int]]) -> bool:

        total_sum = 0
        for nums in grid:
            total_sum += sum(nums)
        if total_sum % 2:
            return False
        
        cur_sum = 0
        n, m = len(grid), len(grid[0])
        for i in range(n):
            cur_sum += sum(grid[i])
            if cur_sum + cur_sum == total_sum:
                return True

        cur_sum = 0
        for j in range(m):
            for i in range(n):
                cur_sum += grid[i][j]
            if cur_sum + cur_sum == total_sum:
                return True
        return False
        