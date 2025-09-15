class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        words = text.split(' ')
        brokenLetters = set(brokenLetters)

        ans = len(words)
        for word in words:
            word = set(word)
            for ch in word:
                if ch in brokenLetters:
                    ans -= 1
                    break
        return ans