class Solution:
    def vowelConsonantScore(self, s: str) -> int:
        v, c = 0, 0
        store = ('a', 'e', 'i', 'o', 'u')
        for ch in s:
            if ch in store:
                v += 1
            elif 'a' <= ch <= 'z':
                c += 1
        if c:
            return floor(v / c)
        return 0