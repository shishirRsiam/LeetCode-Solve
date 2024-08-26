class Solution 
{
public:
    vector<int>a;
    void postOrder(TreeNode*root)
    {
        if(root == NULL) return;
        postOrder(root->left);
        postOrder(root->right);
        a.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) 
    {
        postOrder(root);
        return a;
    }
};