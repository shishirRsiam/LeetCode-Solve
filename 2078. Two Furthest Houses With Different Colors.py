class Solution:
    def maxDistance(self, colors: List[int]) -> int:
        ans = -1
        n = len(colors)
        seen = set()
        for i in range(n):
            if colors[i] in seen:
                continue
            seen.add(colors[i])
            for j in range(n - 1, i, -1):
                if colors[i] != colors[j]:
                    ans = max(ans, abs(i - j))
                    break
        return ans