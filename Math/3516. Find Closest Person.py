class Solution:
    def findClosest(self, x: int, y: int, z: int) -> int:
        x, y = abs(z - x), abs(z - y)
        if x == y:
            return 0
        return 2 if x > y else 1