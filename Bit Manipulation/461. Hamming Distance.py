class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        bin_x = bin(x)[2:]
        bin_y = bin(y)[2:]
        max_len = max(len(bin_x), len(bin_y))

        for _ in range(max_len - len(bin_x)):
            bin_x = "0" + bin_x
        for _ in range(max_len - len(bin_y)):
            bin_y = "0" + bin_y

        ans = 0
        for i in range(max_len):
            ans += bin_x[i] != bin_y[i]
        return ans