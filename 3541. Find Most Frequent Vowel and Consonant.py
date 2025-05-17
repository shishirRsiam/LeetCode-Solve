class Solution:
    def maxFreqSum(self, s: str) -> int:
        count = Counter(s)
        maxVowel, maxCosonent = 0, 0
        for ch in range(97, 123):
            ch = chr(ch)
            if ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u':
                maxVowel = max(maxVowel, count[ch])
            else:
                maxCosonent = max(maxCosonent, count[ch])
        return maxVowel + maxCosonent