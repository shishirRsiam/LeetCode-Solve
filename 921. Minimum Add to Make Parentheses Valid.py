class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        count, ans = 0, 0

        for ch in s:
            if ch =='(': count += 1
            elif count: count -= 1
            else: ans += 1
        return ans + count