class Solution:
    def residuePrefixes(self, s: str) -> int:
        ans = 0
        store = set()
        for i in range(len(s)):
            store.add(s[i])
            ans += len(store) == ((i + 1) % 3)
        return ans