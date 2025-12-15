class Solution:
    def getDescentPeriods(self, prices: List[int]) -> int:
        prices += [-1]
        ans, count, n = 0, 1, len(prices)
        for i in range(1, n):
            if prices[i] + 1 == prices[i - 1]:
                count += 1
            else:
                ans += count * (count + 1) // 2
                count = 1
        return ans