class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        ans, n = 0, len(s)
        a, b, c = -1, -1, -1 
        for i in range(n):
            if s[i] == 'a': a = i
            elif s[i] == 'b': b = i
            elif s[i] == 'c': c = i
            ans += min(a, b, c) + 1
        return ans