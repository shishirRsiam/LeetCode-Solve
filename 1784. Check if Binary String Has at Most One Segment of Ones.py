class Solution:
    def checkOnesSegment(self, s: str) -> bool:
        return sum([s[i] != s[i + 1] for i in range(len(s) - 1)]) <= 1