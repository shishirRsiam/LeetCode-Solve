class Solution:
    def canBeEqual(self, s1: str, s2: str) -> bool:
        n = len(s1)
        s1 = [(s1[i], i % 2) for i in range(n)]
        s2 = [(s2[i], i % 2) for i in range(n)]
        s1.sort()
        s2.sort()
        
        for i in range(n):
            if (s1[i][0] != s2[i][0]) or (s1[i][1] != s2[i][1]):
                return False
        return True