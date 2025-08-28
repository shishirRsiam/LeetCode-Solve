class Solution:
    def sortMatrix(self, grid: List[List[int]]) -> List[List[int]]:
        store = defaultdict(list)
        n, m = len(grid), len(grid[0])
        for i in range(n):
            for j in range(m):
                index = i - j
                store[index].append(grid[i][j])
        
        for index in store:
            store[index].sort()
            if index < 0:
                store[index].reverse()

        for i in range(n):
            for j in range(m):
                index = i - j
                grid[i][j] = store[i - j].pop()
        
        return grid