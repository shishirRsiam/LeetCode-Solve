class Solution:
    def sumAndMultiply(self, n: int) -> int:
        all_sum = 0
        s = ''
        for ch in str(n):
            if not int(ch):
                continue
            all_sum += int(ch)
            s += ch
        return 0 if not s else int(s) * all_sum