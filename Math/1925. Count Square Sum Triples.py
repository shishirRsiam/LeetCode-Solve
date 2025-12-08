class Solution:
    def countTriples(self, n: int) -> int:
        ans = 0
        store_c2 = set([i * i for i in range(1, n + 1)])
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                a2b2 = (i * i) + (j * j)
                if a2b2 > n * n:
                    break
                ans += a2b2 in store_c2
        return ans