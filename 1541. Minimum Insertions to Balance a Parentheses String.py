class Solution:
    def minInsertions(self, s: str) -> int:
        ans, count = 0, 0
        s = s.replace('))', '*')
        for ch in s:
            if ch == ')': ans += 1

            if ch == '(': count += 1
            elif not count: ans += 1
            else: count -= 1
        return ans + (count * 2)
