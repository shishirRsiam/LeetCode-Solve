class Solution:
    def makeFancyString(self, s: str) -> str:
        ans = ""
        for ch in s:
            if len(ans) > 1 and ch == ans[-1] == ans[-2]:
                continue
            ans += ch
        return ans