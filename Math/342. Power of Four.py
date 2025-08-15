class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        for i in range(20):
            if pow(4, i) == n:
                return True
        return False