class Solution:
    def stoneGameIII(self, stoneValue: List[int]) -> str:
        n = len(stoneValue)

        @cache
        def dfs(i):
            if i >= n: return 0
            
            take1 = stoneValue[i] - dfs(i + 1)

            take2, take3 = -inf, -inf
            if i + 1 < n:
                take2 = (stoneValue[i] + stoneValue[i + 1]) - dfs(i + 2)
            if i + 2 < n:
                take3 = (stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2]) - dfs(i + 3)

            return max(take1, take2, take3)

        ans = dfs(0)

        if ans == 0:
            return 'Tie'
        if ans > 0:
            return 'Alice'
        return 'Bob'