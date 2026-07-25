class Solution:
    def maxProduct(self, n: int) -> int:
        s = str(n)
        max_ch = max(s)
        if s.count(max_ch) > 1:
            return int(max_ch) * int(max_ch)

        s = s.replace(max_ch, '0')
        return int(max(s)) * int(max_ch)