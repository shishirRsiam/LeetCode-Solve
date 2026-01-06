class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        store = defaultdict(int)

        def dfs(node, depth):
            if not node: return 0
            store[depth] += node.val 
            dfs(node.left, depth + 1)     
            dfs(node.right, depth + 1)  
        dfs(root, 1)   

        maxSumLevel, maxSum = -1, -10**6
        for level in store:
            if maxSum < store[level]:
                maxSumLevel = level
                maxSum = store[level]
        return maxSumLevel