class Solution:
    def sumZero(self, n: int) -> List[int]:
        ans = []
        for i in range(1, int(n / 2) + 1):
            ans += [i, -i]
        if n % 2:
            ans += [0]
        return ans