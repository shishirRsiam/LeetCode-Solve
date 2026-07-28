class Solution:
    def smallestPalindrome(self, s: str) -> str:
        n = len(s)
        ans = [''] * n

        i = 0
        store = Counter(s)
        
        for ch in ascii_lowercase:
            if store[ch] % 2:
                ans[n // 2] = ch
            
            while store[ch] > 1:
                ans[i] = ans[n - i - 1] = ch
                store[ch] -= 2
                i += 1
                
        return ''.join(ans)