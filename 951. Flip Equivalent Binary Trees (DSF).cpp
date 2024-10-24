class Solution {
public:
    void DFS(TreeNode* root, unordered_map<int, set<int>>&store, int parent)
    {
        if(!root) return;
        store[parent].insert(root->val);
        DFS(root->left, store, root->val);
        DFS(root->right, store, root->val);
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) 
    {
        unordered_map<int, set<int>>store1, store2;
        DFS(root1, store1, -1);
        DFS(root2, store2, -1);

        return store1 == store2;
    }
};