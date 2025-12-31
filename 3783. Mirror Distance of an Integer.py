class Solution:
    def mirrorDistance(self, n: int) -> int:
        return abs(int(str(n)[::-1]) - n)