class Solution:
    def countCommas(self, n: int) -> int:
        ans = 0
        for i in range(1000, n + 1):
            n = len(str(i))
            while n > 3:
                ans += 1
                n -= 3
        return ans
        