class Solution:
    def reverseDegree(self, s: str) -> int:
        ans = 0
        for i in range(len(s)):
            ans += (26 - (ord(s[i]) - ord('a'))) * (i + 1)
        return ans
        