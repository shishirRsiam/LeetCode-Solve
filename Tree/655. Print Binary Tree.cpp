class Solution {
public:
    int getDepth(TreeNode* root)
    {
        if(not root) return 0;
        return max(getDepth(root->left), getDepth(root->right)) + 1;
    }
    void makeTree(TreeNode* root, int i, int depth, vector<vector<string>>& ans, int maxNode)
    {
        if(not root) return;
        
        ans[depth][i] = to_string(root->val);
        int offset = (maxNode + 1) / pow(2, depth + 2);

        makeTree(root->left, i - offset, depth + 1, ans, maxNode);
        makeTree(root->right, i + offset, depth + 1, ans, maxNode);
    }
    vector<vector<string>> printTree(TreeNode* root) 
    {
        int depth = getDepth(root), maxNode = pow(2, depth) - 1;
        vector<vector<string>> ans(depth, vector<string>(maxNode));
        makeTree(root, maxNode / 2, 0, ans, maxNode);
        return ans;
    }
};