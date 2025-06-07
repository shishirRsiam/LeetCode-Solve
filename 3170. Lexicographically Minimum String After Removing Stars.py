class Solution:
    def clearStars(self, s: str) -> str:
        n = len(s)
        not_use = set()
        store = defaultdict(list)
        for i in range(n):
            if s[i] == '*':
                for ch in ascii_lowercase:
                    if len(store[ch]):
                        not_use.add(store[ch][-1])
                        store[ch].pop()
                        break
            else:
                store[s[i]].append(i)

        ans = ""
        for i in range(n):
            if s[i] == '*' or i in not_use:
                continue
            ans += s[i]
        return ans