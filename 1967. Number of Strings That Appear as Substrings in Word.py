class Solution:
    def numOfStrings(self, patterns: List[str], word: str) -> int:
        return sum([s in word for s in patterns])
    
class Solution:
    def numOfStrings(self, patterns: List[str], word: str) -> int:
        ans = 0
        for s in patterns:
            ans += s in word
        return ans

