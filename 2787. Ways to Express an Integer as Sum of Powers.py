class Solution:
    def numberOfWays(self, n: int, x: int) -> int:
        mod = int(1e9 + 7)
        cache = [[-1 for _ in range(n+1)] for _ in range(n+1)]
        
        def solve(cur_number, cur_sum):
            if cur_sum == n:
                return 1
            if cur_number > n or cur_sum > n:
                return 0

            if cache[cur_number][cur_sum] != -1:
                return cache[cur_number][cur_sum]

            not_take = solve(cur_number + 1, cur_sum)
            take = solve(cur_number + 1, cur_sum + pow(cur_number, x, mod))
            cache[cur_number][cur_sum] = (take + not_take) % mod
            return cache[cur_number][cur_sum]

        return solve(1, 0)