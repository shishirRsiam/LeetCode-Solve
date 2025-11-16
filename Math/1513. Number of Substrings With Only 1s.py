class Solution:
    def numSub(self, s: str) -> int:
        mod = int(1e9 + 7)

        s += '0'
        count, ans = 0, 0
        for ch in s:
            if ch == '1':
                count += 1
            else:
                ans += (count * (count + 1) / 2) % mod
                count = 0
        return int(ans % mod)
