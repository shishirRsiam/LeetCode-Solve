class Solution:
    def maxSumOfSquares(self, num: int, sum: int) -> str:
        if (num * 9) < sum:
            return ""

        ans = ''
        while num and sum:
            can_add = min(9, sum)

            num -= 1
            sum -= can_add
            ans += str(can_add)

        return ans + '0' * num