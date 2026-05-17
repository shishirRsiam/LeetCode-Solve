class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        visited = set()

        def dfs(i):
            if not 0 <= i < len(arr):
                return False

            if i in visited:
                return False

            if arr[i] == 0:
                return True

            visited.add(i)

            return dfs(i + arr[i]) or dfs(i - arr[i])

        return dfs(start)