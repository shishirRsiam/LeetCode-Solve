class Solution:
    def findTheLongestBalancedSubstring(self, s: str) -> int:
        ans = 0
        for i in range(1, 26):
            balanced_binary = '0' * i + '1' * i
            if balanced_binary not in s: break
            ans = i + i
        return ans