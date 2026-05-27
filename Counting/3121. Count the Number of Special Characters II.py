class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        n = len(word)
        store = defaultdict(int)
        for i in range(n):
            if word[i].islower():
                store[word[i]] = i
            elif word[i] not in store:
                store[word[i]] = i

        ans = 0
        for ch in ascii_lowercase:
            CH = ch.upper()
            if ch in store and CH in store:
                ans += store[ch] < store[CH]
        return ans