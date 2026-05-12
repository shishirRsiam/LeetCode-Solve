class Solution:
    def minimumEffort(self, tasks: List[List[int]]) -> int:
        ans = 0
        tasks.sort(key=lambda x: x[1] - x[0])
        for ac, mn in tasks:
            ans = max(ans + ac, mn)
        return ans