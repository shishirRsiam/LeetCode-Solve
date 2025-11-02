class Solution:
    def countUnguarded(self, m: int, n: int, guards: List[List[int]], walls: List[List[int]]) -> int:
        grid = [['.'] * n for _ in range(m)]

        for x, y in walls:
            grid[x][y] = 'w'
        for x, y in guards:
            grid[x][y] = 'g'

        def fill_row_col(i, j):
            next_row = j + 1
            while next_row < n:
                if grid[i][next_row] in ('w', 'g'):
                    break
                grid[i][next_row] = 'v'
                next_row += 1

            prev_row = j - 1
            while prev_row >= 0:
                if grid[i][prev_row] in ('w', 'g'):
                    break
                grid[i][prev_row] = 'v'
                prev_row -= 1

            next_col = i + 1
            while next_col < m:
                if grid[next_col][j] in ('w', 'g'):
                    break
                grid[next_col][j] = 'v'
                next_col += 1
            
            prev_col = i - 1
            while prev_col >= 0:
                if grid[prev_col][j] in ('w', 'g'):
                    break
                grid[prev_col][j] = 'v'
                prev_col -= 1

        for i, j in guards:
            fill_row_col(i, j)
            
        ans = 0
        for row in grid:
            for ch in row:
                if ch == '.':
                    ans += 1
        return ans