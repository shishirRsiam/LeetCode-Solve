class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        n = len(prices)
        stact, ans = [], [0] * n

        for i in range(n):
            while stact and prices[stact[-1]] >= prices[i]:
                ans[stact[-1]] = prices[stact[-1]] - prices[i]
                stact.pop()
            stact.append(i)
            
        for idx in stact:
            ans[idx] = prices[idx]
        
        return ans