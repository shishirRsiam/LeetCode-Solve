class Solution:
    def rotateGrid(self, grid: List[List[int]], op: int) -> List[List[int]]:
        n, m = len(grid), len(grid[0])

        store = []
        l, r = n, m
        limit = min(n, m) // 2
        for j in range(limit):
            temp = []
            for k in range(j, r):
                temp.append(grid[j][k])
            for k in range(j + 1, l):
                temp.append(grid[k][r - 1])
            for k in range(r - 2, j - 1, -1):
                temp.append(grid[l - 1][k])
            for k in range(l - 2, j, -1):
                temp.append(grid[k][j])

            l -= 1
            r -= 1
            store.append(temp)

        for i in range(len(store)):
            k = op % len(store[i])
            store[i] = store[i][k:] + store[i][:k]

        cur = 0
        l, r = n, m
        for j in range(limit):
            i = 0
            for k in range(j, r):
                grid[j][k] = store[cur][i]
                i += 1
            for k in range(j + 1, l):
                grid[k][r - 1] = store[cur][i]
                i += 1

            for k in range(r - 2, j - 1, -1):
                grid[l - 1][k] = store[cur][i]
                i += 1
            for k in range(l - 2, j, -1):
                grid[k][j] = store[cur][i]
                i += 1
            l -= 1
            r -= 1
            cur += 1
        
        return grid