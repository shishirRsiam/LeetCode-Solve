class Solution:
    def getNoZeroIntegers(self, n: int) -> List[int]:
        loop = int(n / 2) + 2
        for i in range(loop):
            if '0' in str(i) or '0' in str(n - i):
                continue
            return [i, n - i]
        return None