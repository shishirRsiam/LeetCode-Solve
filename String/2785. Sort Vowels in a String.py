class Solution:
    def is_vowel(self, char):
        return char.lower() in 'aeiou'
    def sortVowels(self, s: str) -> str:
        ans = [ch  for ch in s]
        vowel = [ch for ch in s if self.is_vowel(ch)]
        vowel.sort()
        
        n, cur = len(ans), 0
        for i in range(n):
            if self.is_vowel(s[i]):
                ans[i] = vowel[cur]
                cur += 1
        return ''.join(ans)