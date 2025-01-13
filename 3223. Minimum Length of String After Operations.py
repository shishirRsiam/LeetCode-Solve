class Solution:
    def minimumLength(self, s: str) -> int:
        freq = [0] * 26
        for ch in s:
            freq[ord(ch) - ord('a')] += 1

        ans = 0
        for i in range(26):
            if freq[i]:
                ans += 1
                if freq[i] % 2 == 0:
                    ans += 1 
        return ans
    
from collections import Counter
class Solution(object):
    def minimumLength(self, s):
        mp = Counter(s)
        ans = 0
        for ch, cnt in mp.items():
            ans += 1
            if not cnt % 2:
                ans += 1
        return ans