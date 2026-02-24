class Solution:
    def sumRootToLeaf(self, root: Optional[TreeNode]) -> int:
        def dfs(node, prev):
            if not node:
                return 0
            prev = prev + str(node.val)
            if not node.left and not node.right:
                return int(prev, 2)
            return dfs(node.left, prev) + dfs(node.right, prev)
        return dfs(root, '')