# 1680. Concatenation of Consecutive Binary Numbers

class Solution:
    def concatenatedBinary(self, n: int) -> int:
        return int(''.join([bin(i)[2:] for i in range(1, n + 1)]), 2) % (10 ** 9 + 7)


class Solution:
    def concatenatedBinary(self, n: int) -> int:
        store = [bin(i)[2:] for i in range(1, n + 1)]
        return int(''.join(store), 2) % (10 ** 9 + 7)
    
class Solution:
    def concatenatedBinary(self, n: int) -> int:
        s = ""
        MOD = 10 ** 9 + 7
        for i in range(1, n + 1):
            s += bin(i)[2:]
        return int(s, 2) % MOD