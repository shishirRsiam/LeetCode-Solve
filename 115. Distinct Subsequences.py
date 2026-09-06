class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        n, m = len(s), len(t)

        @cache
        def dp(i, j):
            if j == m:
                return 1
            if i == n:
                return 0
            
            count = 0
            if s[i] == t[j]:
                count = dp(i + 1, j + 1)
            return count + dp(i + 1, j)

        return dp(0, 0)
        