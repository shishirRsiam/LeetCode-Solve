class Solution:
    def evaluate(self, s: str, knowledge: list[list[str]]) -> str:
        store = {key:val for key, val in knowledge}

        ans = ''
        i, n = 0, len(s)
        while i < n:
            if s[i] == '(':
                i += 1
                key = ''
                while s[i] != ')':
                    key += s[i]
                    i += 1
                ans += store.get(key, '?')
            else:
                ans += s[i]
            i += 1
        return ans