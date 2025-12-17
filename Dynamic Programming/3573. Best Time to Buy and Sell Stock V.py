class Solution:
    def maximumProfit(self, prices: List[int], k: int) -> int:
        n = len(prices)
        NEG_INF = -10**18

        cache = {}
        
        def solve(day, k_left, state):
            if day == n:
                return 0 if state == 0 else NEG_INF
            if k_left == 0:
                return 0 if state == 0 else NEG_INF
            key = str(day) + "&" + str(k_left) + "&" + str(state)
            if key in cache:
                return cache[key]

            if state == 0:
                skip = solve(day + 1, k_left, 0)
                buy_long = -prices[day] + solve(day + 1, k_left, 1)
                sell_short = prices[day] + solve(day + 1, k_left, 2)
                cache[key] = max(skip, buy_long, sell_short)

            elif state == 1:
                skip = solve(day + 1, k_left, 1)
                sell_close = prices[day] + solve(day + 1, k_left - 1, 0)
                cache[key] = max(skip, sell_close)

            else:
                skip = solve(day + 1, k_left, 2)
                buy_close = -prices[day] + solve(day + 1, k_left - 1, 0)
                cache[key] = max(skip, buy_close)
            
            return cache[key] or 0

        return solve(0, k, 0)