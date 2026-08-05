class Solution:
    def remainingMethods(self, n: int, k: int, invocations: List[List[int]]) -> List[int]:
        adj = defaultdict(list)
        for u, v in invocations:
            adj[u].append(v)
        
        suspicious = set()
        def dfs(node):
            if node in suspicious: return 

            suspicious.add(node)
            for child in adj[node]:
                dfs(child)
            
        dfs(k)

        for u, v in invocations:
            if u not in suspicious and v in suspicious:
                return list(range(n))
                
        return [i for i in range(n) if i not in suspicious]
