class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        n, m, ans = len(strs), len(strs[0]), 0
        for j in range(m):
            store = []
            for i in range(n):
                store.append(strs[i][j])
            ans += store != sorted(store)
        return ans