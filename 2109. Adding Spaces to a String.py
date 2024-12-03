class Solution:
    def addSpaces(self, s: str, spaces: List[int]) -> str:
        ans = ''
        idx, size = 0, len(spaces)
        for i, ch in enumerate(s):
            if idx < size and i == spaces[idx]:
                idx += 1
                ans += ' '
            ans += ch
        return ans


class Solution(object):
    def addSpaces(self, s, spaces):
        result = []
        i, j = 0, 0
        n, m = len(s), len(spaces)
        
        while j < m:
            if i == spaces[j]:
                result.append(' ')
                j += 1
            result.append(s[i])
            i += 1
        
        while i < n:
            result.append(s[i])
            i += 1
        
        return ''.join(result)