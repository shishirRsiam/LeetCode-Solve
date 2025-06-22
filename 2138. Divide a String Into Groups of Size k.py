class Solution:
    def divideString(self, s: str, k: int, fill: str) -> List[str]:
        while len(s) % k:
            s += fill
        
        ans = []
        for i in range(0, len(s), k):
            ans.append(s[i:i+k])
        return ans