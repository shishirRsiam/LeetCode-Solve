class Solution:
    def maxKDivisibleComponents(self, n: int, edges: List[List[int]], values: List[int], k: int) -> int:
        adj = defaultdict(list)
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        ans = 0
        def dfs(node, parent):
            cur_sum = values[node]
            for child in adj[node]:
                if child != parent:
                    cur_sum += dfs(child, node)
            if cur_sum % k == 0:
                nonlocal ans
                ans += 1
                return 0
            return cur_sum
        dfs(0, -1)
        return ans