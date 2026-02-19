class Solution:
    def countBinarySubstrings(self, s: str) -> int:
        s += '-'
        store = []
        count, n = 0, len(s)
        for i in range(n):
            if s[i] == s[i - 1]:
                count += 1
            else:
                store.append(count)
                count = 1

        return sum([min(store[i], store[i - 1]) for i in range(1, len(store))])