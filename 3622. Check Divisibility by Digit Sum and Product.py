class Solution:
    def checkDivisibility(self, n: int) -> bool:
        digit_sum, digit_mul = 0, 1
        for ch in str(n):
            digit_mul *= int(ch)
            digit_sum += int(ch)

        return n % (digit_mul + digit_sum) == 0