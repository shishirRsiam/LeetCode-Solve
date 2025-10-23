class Solution:
    def hasSameDigits(self, s: str) -> bool:
        if len(s) == 2:
            return s[0] == s[1]
        
        new_s = ""
        for i in range(1, len(s)):
            num = (int(s[i]) + int(s[i - 1])) % 10
            new_s += str(num)
        return self.hasSameDigits(new_s)