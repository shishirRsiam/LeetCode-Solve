class Solution:
    def differenceOfSums(self, n: int, m: int) -> int:
        num1 = [num for num in range(1, n + 1) if num % m]
        num2 = [num for num in range(1, n + 1) if not num % m]

        return sum(num1) - sum(num2)