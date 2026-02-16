class Solution:
    def reverseBits(self, n: int) -> int:
        return int(bin(n)[2:].zfill(32)[::-1], 2)
    

class Solution:
    def reverseBits(self, n: int) -> int:
        bits = bin(n)[2:]
        bits = bits.zfill(32)
        bits = bits[::-1]

        return int(bits, 2)