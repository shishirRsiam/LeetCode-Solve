class Solution:
    def findMissingAndRepeatedValues(self, grid: List[List[int]]) -> List[int]:
        ans = [0, 0]
        store = defaultdict(int)
        for row in grid:
            for val in row:
                store[val] += 1

        val = len(grid) * len(grid)
        while val:
            if store[val] == 0:
                ans[1] = val
            elif store[val] == 2:
                ans[0] = val
            val -= 1
        return ans