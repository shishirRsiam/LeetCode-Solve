class Solution:
    def findDegrees(self, matrix: list[list[int]]) -> list[int]:
        return [row.count(1) for row in matrix]