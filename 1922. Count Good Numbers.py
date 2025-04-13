class Solution:
    def countGoodNumbers(self, n: int) -> int:
        mod = 1000000007
        even, odd = n / 2, (n / 2) + (n % 2)

        return pow(5, int(odd), mod) * pow(4, int(even), mod) % mod