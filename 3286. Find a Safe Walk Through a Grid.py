class Solution:
    def findSafeWalk(self, grid: List[List[int]], health: int) -> bool:
        max_heap = []
        visited = set()
        heappush(max_heap, (-(health - grid[0][0]), (0 , 0)))
        dir = ((0, 1), (0, -1), (1, 0), (-1, 0))

        n, m = len(grid), len(grid[0])
        while max_heap:
            h, (i, j) = heappop(max_heap)
            h = -h
            if not h:
                return False
                
            if i == n - 1 and j == m - 1:
                return True

            for ii, jj in dir:
                ni, nj = ii + i, jj + j
                key = (ni, nj)
                if ni < 0 or nj < 0 or ni == n or nj == m or key in visited:
                    continue

                visited.add(key)
                heappush(max_heap, (-(h - grid[ni][nj]), (ni, nj)))
            
        return False