class Solution:
    def maxScore(self, s: str) -> int:
        ans, n = 0, len(s)
        for i in range(1, n):
            left_count = s[:i].count('0')
            right_count = s[i:n].count('1')
            ans = max(ans, left_count + right_count)
        return ans