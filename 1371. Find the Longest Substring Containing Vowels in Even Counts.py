class Solution(object):
    def findTheLongestSubstring(self, s):
        voules = {
            'a': 1, 'e': 2, 'i': 4, 'o': 8, 'u': 16,
        }

        lastSeenIndex = {
            0: -1,
        }
        
        n = len(s)
        maxLen, musk = 0, 0
        for i in range(n):
            if s[i] in "aeiou":
                musk ^= voules[s[i]]
            if musk in lastSeenIndex:
                maxLen = max(maxLen, i - lastSeenIndex[musk])
            else:
                lastSeenIndex[musk] = i
        return maxLen