class Solution:
    def trimTrailingVowels(self, s: str) -> str:
        while s and s[-1] in ['a', 'e', 'i', 'o', 'u']:
            s = s[:-1]
        return s