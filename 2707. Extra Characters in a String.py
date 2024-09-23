class Solution(object):
    def solve(self, idx, n, s, st, dp):
        if idx == n: return 0

        if dp[idx] != -1:
            return dp[idx]

        cur = ""
        minExtra = n
        for i in range(idx, n):
            cur += s[i]

            curExtra = 0
            if cur not in st:
                curExtra += len(cur)
            nextExtra = self.solve(i+1, n, s, st, dp)

            minExtra = min(minExtra, curExtra + nextExtra)

        dp[idx] = minExtra
        return dp[idx]

    def minExtraChar(self, s, dictionary):
        n = len(s)
        dp = [-1] * (n + 5)
        st = set(dictionary)
        return self.solve(0, n, s, st, dp)