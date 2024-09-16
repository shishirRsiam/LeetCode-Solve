class Solution(object):
    def longestContinuousSubstring(self, s):
        n = len(s)
        ans, cnt = 1, 1
        for i in range(1, n):
            if ord(s[i]) == ord(s[i - 1]) + 1: 
                cnt += 1
            else:
                cnt = 1
            ans = max(ans, cnt)
        return ans