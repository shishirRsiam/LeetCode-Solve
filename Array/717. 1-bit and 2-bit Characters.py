class Solution:
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        i, past, n, = 0, 1, len(bits)
        while i < n:
            if bits[i]:
                past = 2
                i += 1
            else:
                past = 1
            i += 1
        return True if past == 1 else False