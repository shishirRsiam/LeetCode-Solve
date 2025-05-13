class Solution:
    def lengthAfterTransformations(self, s: str, t: int) -> int:
        count = [0] * 26
        n, mod = len(s), int(1e9 + 7)
        for i in range(n):
            count[ord(s[i]) - ord('a')] += 1
        
        for _ in range(t):
            temp_count = [0] * 26
            temp_count[0] = count[25]
            temp_count[1] = count[25]
            for index in range(25):
                temp_count[index + 1] += count[index] % mod
            count = temp_count
        
        ans = 0
        for index in range(26):
            ans += count[index] % mod
        return ans % mod