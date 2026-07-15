class Solution:
    def gcdOfOddEvenSums(self, n: int) -> int:
        odd, even = 1, 2
        odd_sum, even_sum = 0, 0
        for i in range(n):
            odd_sum += odd
            even_sum += even
            odd += 2
            even += 2
        return gcd(odd_sum, even_sum)