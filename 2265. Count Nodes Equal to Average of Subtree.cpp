class Solution {
public:
    tuple<int, int> DFS(TreeNode* root, int &ans)
    {
        if(not root) return {0, 0};
        auto [leftVal, leftCount] = DFS(root->left, ans);
        auto [rightVal, rightCount] = DFS(root->right, ans);

        int count = leftCount + rightCount + 1;
        int sum = leftVal + rightVal + root->val;

        ans += ((sum / count) == root->val);
        return {sum, count};
    }
    int averageOfSubtree(TreeNode* root) 
    {
        int ans = 0;
        DFS(root, ans);
        return ans;
    }
};