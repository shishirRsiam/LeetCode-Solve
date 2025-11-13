class Solution:
    def maxOperations(self, s: str) -> int:
        s += "1"
        foundZero = False
        oneCount, ans = 0, 0
        for ch in s:
            if ch == '1':
                if foundZero:
                    ans += oneCount
                    foundZero = False
                oneCount += 1
            else:
                foundZero = True
        return ans
    

class Solution(object):
    def maxOperations(self, s):
        n = len(s)
        ans, oneCount, i = 0, 0, 0
        while i < n:
            if s[i] == '0':
                ans += oneCount
                while i < n and s[i] == '0':
                    i += 1
            else:
                oneCount += 1
                i += 1
        return ans