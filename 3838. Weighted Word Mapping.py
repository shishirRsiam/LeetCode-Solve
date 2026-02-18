class Solution:
    def mapWordWeights(self, words: List[str], weights: List[int]) -> str:
        ans, store = '', ascii_lowercase[::-1]
        for word in words:
            index = sum([weights[ord(ch) - ord('a')] for ch in word]) % 26
            ans += store[index]
        return ans