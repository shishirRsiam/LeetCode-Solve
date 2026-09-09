class Solution:
    def countCommas(self, n: int) -> int:
        cur = 1000
        if n < cur:
            return 0

        def get_comma_count(num):
            m = len(str(cur))
            return (m - 1) // 3

        ans, count = 0, 1
        while cur <= n:
            if cur * 10 > n: break

            next_cur = cur * 10
            count = get_comma_count(cur)
            ans += (count * (next_cur - cur))
            cur = next_cur

        count = get_comma_count(cur)
        return ans + (count * (n - cur)) + count
