class Solution {
public:
    void helper(TreeNode *root, int out, int &res)
    {
        if (!root) return;

        out = (out << 1) + root->val;

        if (!root->left && !root->right)
        {
            res += out;
            return;
        }

        helper(root->left, out, res);
        helper(root->right, out, res);
    }

    int sumRootToLeaf(TreeNode *root)
    {
        int res = 0;
        helper(root, 0, res);
        return res;
    }
};