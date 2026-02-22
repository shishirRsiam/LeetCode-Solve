class Solution:
    def binaryGap(self, n: int) -> int:
        binary = bin(n)[2:]
        if binary.count('1') < 2:
            return 0

        ans, prev, n = 0, -1, len(binary)
        for i in range(n):
            if binary[i] == '1':
                ans = max(ans, i - prev)
                prev = i
        return ans