class Solution:
    def mapWordWeights(self, words: List[str], weights: List[int]) -> str:
        ans, store = '', ascii_lowercase[::-1]
        for word in words:
            index = sum([weights[ord(ch) - ord('a')] for ch in word]) % 26
            ans += store[index]
        return ans

class Solution:
    def mapWordWeights(self, words: List[str], weights: List[int]) -> str:
        ans = []
        reverse_words = ascii_lowercase[::-1]
        for w in words:
            sum_ord = sum([weights[ord(ch) - ord('a')] for ch in w])     
            ans.append(reverse_words[sum_ord % 26])
        return ''.join(ans)