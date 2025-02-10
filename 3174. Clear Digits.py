class Solution:
    def clearDigits(self, s: str) -> str:
        ans = []
        for ch in s:
            if ch.isdigit() and ans: ans.pop()
            else: ans.append(ch)
        return ''.join(ans)