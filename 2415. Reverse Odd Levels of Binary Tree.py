class Solution:
    def reverseOddLevels(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def swapNode(node1, node2, depth):
            if not node1 or not node2: return
            if depth % 2:
                node1.val, node2.val = node2.val, node1.val
            swapNode(node1.left, node2.right, depth + 1)
            swapNode(node1.right, node2.left, depth + 1)
        
        swapNode(root.left, root.right, 1)
        return root