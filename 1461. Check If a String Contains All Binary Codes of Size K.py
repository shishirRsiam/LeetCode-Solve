class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        seen = set()        
        need = int(('1' * k), 2) + 1
        for i in range(len(s) - k + 1):
            seen.add(s[i:i+k])
            if len(seen) == need:
                return True
        return False