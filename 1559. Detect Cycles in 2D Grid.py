class Solution:
    def containsCycle(self, grid: List[List[str]]) -> bool:
        store = set()
        for row in grid:
            for ch in row:
                store.add(ch)

        n, m = len(grid), len(grid[0])
        visited = [[False] * m for _ in range(n)]
        dir = [(0,1),(0,-1),(1,0),(-1,0)]
        def dfs(i, j, prev_i, prev_j, target, count):
            if i < 0 or j < 0 or i == n or j == m:
                return False
            if grid[i][j] != target:
                return False
            
            if visited[i][j]:
                return True
            visited[i][j] = True
            for dx, dy in dir:
                ni, nj = i + dx, j + dy

                if ni == prev_i and nj == prev_j:
                    continue

                if dfs(ni, nj, i, j, target, count + 1):
                    return True
            return False

        for target in store:
            visited = [[False] * m for _ in range(n)]
            for i in range(n):
                for j in range(m):
                    if not visited[i][j]:
                        if dfs(i, j, i - 1, j, target, 0):
                            return True
        return False