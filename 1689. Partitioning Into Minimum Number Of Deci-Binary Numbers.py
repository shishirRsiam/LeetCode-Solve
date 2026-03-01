class Solution:
    def minPartitions(self, n: str) -> int:
        return int(max(n))
    
class Solution(object):
    def minPartitions(self, n):
        ans = 0
        for ch in n:
            ans = max(ans, int(ch))
        return ans