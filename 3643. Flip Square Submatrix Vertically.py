class Solution:
    def reverseSubmatrix(self, grid: List[List[int]], x: int, y: int, k: int) -> List[List[int]]:
        store = []
        for i in range(x, x + k):
            store.append(grid[i][y:y+k])
        
        cur = 0
        store.reverse()
        for i in range(x, x + k):
            grid[i][y:y+k] = store[cur]
            cur += 1
        return grid