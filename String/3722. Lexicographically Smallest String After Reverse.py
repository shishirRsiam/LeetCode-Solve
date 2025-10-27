class Solution:
    def lexSmallest(self, s: str) -> str:
        ans = s
        n = len(s)
        for i in range(0, n + 1):
            ans = min(ans, s[:i] + s[i:n][::-1], s[:i][::-1] + s[i:])
        return ans