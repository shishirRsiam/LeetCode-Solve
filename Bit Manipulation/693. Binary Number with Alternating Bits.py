class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        s = bin(n)[2:]
        for i in range(1, len(s)):
            if s[i] == s[i - 1]:
                return False
        return True