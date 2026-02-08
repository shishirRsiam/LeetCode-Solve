
class Solution {
public:
    int hight(TreeNode*root)
    {
        if(!root) return 0;
        int l = hight(root->left);
        int r = hight(root->right);
        return max(l,r)+1;
    }
    bool isBalanced(TreeNode* root) 
    {
        if(!root) return true;
        if(!root->left and !root->right) return true;

        int l = hight(root->left);
        int r = hight(root->right);

        if(abs(l-r) > 1) return false;
        return isBalanced(root->left) and isBalanced(root->right);
    }
};