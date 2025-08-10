class Solution:
    def reorderedPowerOf2(self, n: int) -> bool:
        target = [ch for ch in str(n)]
        target.sort()
        for i in range(33):
            s = [ch for ch in str(pow(2, i))]
            s.sort()
            if s == target:
                return True
        return False