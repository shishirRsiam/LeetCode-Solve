class Solution:
    def __init__(self):
        self.ans = 0
        self.total = 0

    def maxProduct(self, root: Optional[TreeNode]) -> int:
        MOD = 10**9 + 7

        def dfs_sum(node):
            if not node: return 0
            return node.val + dfs_sum(node.left) + dfs_sum(node.right)

        self.total = dfs_sum(root)

        def dfs(node):
            if not node: return 0

            left = dfs(node.left)
            right = dfs(node.right)

            subtree = node.val + left + right
            self.ans = max(self.ans, subtree * (self.total - subtree))
            return subtree

        dfs(root)
        return self.ans % MOD