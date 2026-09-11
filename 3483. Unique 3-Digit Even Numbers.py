class Solution:
    def totalNumbers(self, digits: List[int]) -> int:
        store = set()
        n = len(digits)
        for i in range(n):
            for j in range(n):
                if i == j: continue
                for k in range(n):
                    if i == k or j == k: continue
                    s = f"{digits[i]}{digits[j]}{digits[k]}"
                    if s[0] != '0' and ord(s[-1]) % 2 == 0:
                        store.add(s)
        return len(store)