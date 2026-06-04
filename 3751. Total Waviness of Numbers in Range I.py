class Solution:
    def totalWaviness(self, num1: int, num2: int) -> int:
        ans = 0
        for i in range(num1, num2 + 1):
            s = str(i)
            n = len(s)
            for j in range(1, n - 1):
                ans += s[j - 1] < s[j] > s[j + 1]
                ans += s[j - 1] > s[j] < s[j + 1]
        return ans