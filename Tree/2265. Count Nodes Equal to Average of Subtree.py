class Solution:
    def averageOfSubtree(self, root: TreeNode) -> int:
        def dfs(node):
            if not node: return 0, 0, 0
            
            left_sum, left_count, left_ans = dfs(node.left)
            right_sum, right_count, right_ans = dfs(node.right)

            node_count = 1 + left_count + right_count
            tree_sum = node.val + left_sum + right_sum

            cur_ans = left_ans + right_ans + (tree_sum // node_count == node.val)

            return tree_sum, node_count, cur_ans

        return dfs(root)[2]



class Solution:
    def averageOfSubtree(self, root: TreeNode) -> int:
        ans = []
        def dfs(node):
            if not node:
                return 0, 0
            left_sum, left_count = dfs(node.left)
            right_sum, right_count = dfs(node.right)

            node_count = 1 + left_count + right_count
            tree_sum = node.val + left_sum + right_sum

            if tree_sum // node_count == node.val:
                ans.append(1)

            return tree_sum, node_count
        dfs(root)

        return sum(ans)
    