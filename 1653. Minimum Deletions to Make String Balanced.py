class Solution:
    def minimumDeletions(self, s: str) -> int:
        ans, countB = 0, 0
        for ch in s:
            if ch == 'a':
                ans = min(ans + 1, countB)
            else: countB += 1
        return ans