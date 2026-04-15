class Solution:
    def closestTarget(self, words: List[str], target: str, startIndex: int) -> int:
        if target not in words:
            return -1
        
        ans = 100
        n = len(words)
        for i in range(n):
            if words[i] == target:
                ans = min(ans, abs(i - startIndex), n - abs(i - startIndex))
        return ans