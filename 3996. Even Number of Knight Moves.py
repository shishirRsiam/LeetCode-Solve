class Solution:
    def canReach(self, start: list[int], target: list[int]) -> bool:
        dir = [(-2, -1), (-2, 1), (-1, 2), (-1, -2), (2, -1), (2, 1), (1, -2), (1, 2)]

        visited = set()
        def dfs(i, j, cnt):
            if (i, j) in visited:
                return False
            visited.add((i, j))
            
            if i < 0 or j < 0 or i >= 8 or j >= 8:
                return False
            if i == target[0] and j == target[1]:
                return cnt % 2 == 0
            
            for ni, nj in dir:
                if dfs(i + ni, j + nj, cnt + 1):
                    return True
            return False

        return dfs(start[0], start[1], 0)