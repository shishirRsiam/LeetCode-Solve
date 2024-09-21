class Solution(object):
    def longestPalindrome(self, s):
        n = len(s)
        pi = [0] * n
        for i in range(1, n):
            j = pi[i - 1]
            
            while j and s[i] != s[j]:
                j = pi[j - 1]

            j += s[i] == s[j]
            pi[i] = j

        return pi[n - 1]
    def shortestPalindrome(self, s):
        n = len(s)
        reversed_s = s[::-1]
        size = self.longestPalindrome(s + "&" + reversed_s)
        add_s = ""
        while size < n:
            add_s += s[size]
            size += 1
        add_s = add_s[::-1]
        return add_s + s