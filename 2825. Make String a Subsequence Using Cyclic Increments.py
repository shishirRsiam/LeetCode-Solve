class Solution:
    def canMakeSubsequence(self, str1: str, str2: str) -> bool:
        idx, n = 0, len(str2)

        for ch in str1:
            if idx == n: break

            if ch == str2[idx]:
                idx += 1
                continue

            next_ch = 'a' if ch == 'z' else chr(ord(ch) + 1)
            if next_ch == str2[idx]:
                idx += 1
            
        return idx == n