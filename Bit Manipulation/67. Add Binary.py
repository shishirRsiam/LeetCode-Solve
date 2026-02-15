class Solution:
    def addBinary(self, a: str, b: str) -> str:
        ans = ""
        extra = 0
        max_len = max(len(a), len(b))
        a = a.zfill(max_len)
        b = b.zfill(max_len)
        for i in range(max_len - 1, -1, -1):
            count = extra + (a[i] == '1') + (b[i] == '1')
            if count >= 2:
                extra = 1
                count -= 2
            else:
                extra = 0
            ans = str(count) + ans
        if extra:
            ans = str(extra) + ans
        return ans