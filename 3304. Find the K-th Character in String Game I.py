class Solution:
    def kthCharacter(self, k: int) -> str:
        def GenerateString(s):
            new_str = ""
            for ch in s:
                new_str += 'a' if ch == 'z' else chr(ord(ch) + 1)
            return new_str
        s = "a"
        while len(s) < k:
            s += GenerateString(s)
        return s[k - 1]