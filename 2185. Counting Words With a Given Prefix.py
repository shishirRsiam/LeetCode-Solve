class Solution:
    def prefixCount(self, words: List[str], pref: str) -> int:
        ans = 0
        for word in words:
            ans += word[:len(pref)] == pref
        return ans
    


class Solution(object):
    def prefixCount(self, words, pref):
        ans = 0
        for s in words:
            if s.startswith(pref):
                ans += 1
        return ans
        