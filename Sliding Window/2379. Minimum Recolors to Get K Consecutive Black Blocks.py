class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        cnt = 0
        ans, i, j, n, = sys.maxsize, 0, 0, len(blocks)
        while j < n:
            if blocks[j] == 'W':
                cnt += 1
            if j - i + 1 == k:
                ans = min(ans, cnt)
                if blocks[i] == 'W':
                    cnt -= 1
                i += 1
            j += 1
        return ans