class Solution:
    def minOperations(self, s: str) -> int:
        if len(s) == 2 and s[0] > s[1]:
            return -1

        n = len(s)

        if ''.join(sorted(s)) == s:
            return 0

        if min(s) == s[0] or max(s) == s[-1]:
            return 1

        reverse_s = s[::-1]
        if s.index(min(s)) == n - 1 and reverse_s.index(max(s)) == n - 1:
            return 3

        return 2
        