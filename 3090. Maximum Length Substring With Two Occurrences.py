class Solution:
    def maximumLengthSubstring(self, s: str) -> int:
        n = len(s)

        count = Counter()
        ans, i, j = 0, 0, 0
        while j < n:
            count[s[j]] += 1
            while count[s[j]] > 2:
                count[s[i]] -= 1
                i += 1
            ans = max(ans, j - i + 1)
            j += 1
        return ans