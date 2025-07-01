class Solution:
    def possibleStringCount(self, word: str) -> int:
        word += '.'
        ans, count, n = 1, 0, len(word)
        for i in range(1, n):
            if word[i] == word[i - 1]:
                count += 1
                continue
            ans += count
            count = 0
        return ans