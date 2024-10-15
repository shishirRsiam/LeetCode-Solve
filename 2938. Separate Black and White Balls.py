class Solution:
    def minimumSteps(self, s: str) -> int:
        ans, count = 0, 0
        for ch in s:
            count += ch == '1'
            if ch == '0':
                ans += count
        return ans