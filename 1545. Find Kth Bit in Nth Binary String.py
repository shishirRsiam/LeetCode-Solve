class Solution:
    def findKthBit(self, n: int, k: int) -> str:
        bits = '0'
        for _ in range(n - 1):
            newBits = '1'
            size = len(bits)
            for i in range(size - 1, -1, -1):
                newBits += ('0' if bits[i] == '1' else '1')
            bits += newBits

        return bits[k - 1]