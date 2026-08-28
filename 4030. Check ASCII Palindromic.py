class Solution:
    def isPalindromic(self, s: str) -> bool:
        full_binary = ""
        for ch in s:
            cur_binary = bin(ord(ch))[2:][::-1]
            cur_binary += '0' * (8 - len(cur_binary))
            full_binary += cur_binary
        return full_binary == full_binary[::-1]
        