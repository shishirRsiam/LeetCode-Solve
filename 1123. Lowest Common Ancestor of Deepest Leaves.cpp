class Solution {
public:
    int maxDepth = 0;
    int findMaxDepth(TreeNode* root) 
    {
        if (!root) return 0;
        return 1 + max(findMaxDepth(root->left), findMaxDepth(root->right));
    }
    TreeNode* dfs(TreeNode* root, int depth) 
    {
        if (!root) return nullptr;
        if (depth == maxDepth && !root->left && !root->right) 
            return root;

        TreeNode* left = dfs(root->left, depth + 1);
        TreeNode* right = dfs(root->right, depth + 1);

        if (left && right) return root;
        return left ? left : right;
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) 
    {
        maxDepth = findMaxDepth(root);
        return dfs(root, 1);
    }
};