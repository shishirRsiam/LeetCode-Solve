class Solution:
    def countCompleteComponents(self, n: int, edges: List[List[int]]) -> int:
        adj = defaultdict(list)

        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        visited = set()

        ans = 0

        for i in range(n):
            if i in visited:
                continue
            visited.add(i)
            
            que = deque([i])
            edj_count, node_count = 0, 0
            while que:
                node = que.popleft()

                node_count += 1
                edj_count += len(adj[node])

                for child in adj[node]:
                    if child in visited:
                        continue
                    visited.add(child)
                    que.append(child)
                    
            ans += (node_count * (node_count - 1)) == edj_count

        return ans