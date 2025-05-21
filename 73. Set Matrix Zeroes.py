class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        row, col = set(), set()
        n, m = len(matrix), len(matrix[0])
        
        for i in range(n):
            for j in range(m):
                if not matrix[i][j]:
                    row.add(i)
                    col.add(j)

        for i in row:
            for j in range(m):
                matrix[i][j] = 0
        for j in col:
            for i in range(n):
                matrix[i][j] = 0