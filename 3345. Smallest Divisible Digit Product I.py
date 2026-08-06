class Solution:
    def smallestNumber(self, n: int, t: int) -> int:
        for i in range(n, 110):
            p = 1
            for ch in str(i):
                p *= int(ch)
            if p % t == 0:
                return i
        