class Solution:
    def minScore(self, n: int, roads: List[List[int]]) -> int:
        adj = defaultdict(list)
        for u, v, c in roads:
            adj[u].append((v, c))
            adj[v].append((u, c))
        
        ans = 10 ** 10
        bfs = deque([1])
        visited = set([1])
        while bfs:
            node = bfs.popleft()
            for child, cost in adj[node]:
                ans = min(ans, cost)
                if child in visited:
                    continue
                    
                bfs.append(child)
                visited.add(child)
        return ans