class Solution:
    def maxDifference(self, s: str) -> int:
        count = Counter(s)
        max_odd, min_even = 0, 100
        for ch in ascii_lowercase:
            if count[ch] % 2:
                max_odd = max(max_odd, count[ch])
            elif count[ch]:
                min_even = min(min_even, count[ch])
        return max_odd - min_even