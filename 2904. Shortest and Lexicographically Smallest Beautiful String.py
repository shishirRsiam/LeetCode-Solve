class Solution:
    def shortestBeautifulSubstring(self, s: str, k: int) -> str:
        n = len(s)
        i, j = 0, 0

        ans = "1" * n
        found = False
        count = Counter()
        while j < n:
            count[s[j]] += 1
            while count['1'] > k:
                count[s[i]] -= 1
                i += 1

            while i < n and s[i] == '0':
                i += 1

            if count['1'] == k and s[j] == '1':
                found = True
                new_s = s[i:j+1]
                if len(new_s) == len(ans):
                    ans = min(ans, new_s)
                elif len(new_s) < len(ans):
                    ans = new_s

            j += 1
        return ans if found else ''
