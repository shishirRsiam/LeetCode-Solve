class Solution:
    def soupServings(self, n: int) -> float:
        if n >= 5000:
            return 1

        cache = {}
        def solve(a, b):
            if(a <= 0 and b <= 0): return 0.5
            if(a <= 0): return 1
            if(b <= 0): return 0

            if (a, b) in cache:
                return cache[(a, b)]

            op1 = solve(a - 100, b)
            op2 = solve(a - 75, b - 25)
            op3 = solve(a - 50, b - 50)
            op4 = solve(a - 25, b - 75)
            cache[(a, b)] = (op1 + op2 + op3 + op4) * 0.25
            return cache[(a, b)]
        return solve(n, n)