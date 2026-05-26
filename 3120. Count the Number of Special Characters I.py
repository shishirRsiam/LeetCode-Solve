class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        return sum([ch in word and ch.upper() in word for ch in ascii_lowercase])
    
class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        word = set(word)
        count = 0
        for ch in ascii_lowercase:
            count += ch in word and ch.upper() in word
        return count