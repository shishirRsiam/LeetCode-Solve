class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        store = []
        def dfs(tree):
            if not tree:
                return 0
            l = dfs(tree.left)
            r = dfs(tree.right)
            store.append((l, r))
            return max(l, r) + 1
        dfs(root)

        for l, r in store:
            if abs(l - r) > 1:
                return False
        return True