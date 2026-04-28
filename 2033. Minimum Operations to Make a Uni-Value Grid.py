class Solution:
    def minOperations(self, grid: List[List[int]], x: int) -> int:
        store = []
        for row in grid:
            for val in row:
                store.append(val)
        
        store.sort()
        target = store[len(store) // 2]

        ans = 0
        for val in store:
            extra = abs(val - target)
            if extra % x: return -1
            ans += extra // x
        return ans