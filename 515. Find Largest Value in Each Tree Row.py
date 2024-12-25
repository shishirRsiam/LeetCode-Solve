class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        store = {}
        def DFS(root, depth):
            if not root: return
            if depth in store:
                store[depth] = max(store[depth], root.val)
            else: store[depth] = root.val
            DFS(root.left, depth + 1)
            DFS(root.right, depth + 1)

        DFS(root, 0)
        ans = [0] * len(store)
        for depth in store:
            ans[depth] = store[depth]
        return ans