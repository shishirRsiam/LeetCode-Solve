class Solution:
    def longestPalindrome(self, words: List[str]) -> int:
        visited = set()
        count = Counter(words)

        ans = 0
        flag = True
        for s, cnt in count.items():
            if s in visited:
                continue

            if s[0] == s[1]:
                if cnt % 2:
                    cnt -= 1
                    if flag:
                        ans += 2
                        flag = False
                ans += cnt * 2
                continue

            ss = s[1] + s[0]
            maxAdd = min(cnt, count[ss])
            ans += (maxAdd * 2) * 2

            visited.add(s)
            visited.add(ss)

        return ans