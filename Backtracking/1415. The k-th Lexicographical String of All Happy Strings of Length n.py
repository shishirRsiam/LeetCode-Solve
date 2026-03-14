class Solution:
    def getHappyString(self, n: int, k: int) -> str:
        store = []
        def dfs(s):
            if len(s) > 1:
                if s[-1] == s[-2]:
                    return 
            if len(s) == n:
                store.append(s)
                return 
            dfs(s + 'a')
            dfs(s + 'b')
            dfs(s + 'c')
        dfs("")

        store.sort()
        if k <= len(store):
            return store[k - 1]
        return ""