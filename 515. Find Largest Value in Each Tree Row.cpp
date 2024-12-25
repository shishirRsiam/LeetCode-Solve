class Solution {
public:
    unordered_map<int, int> store, visited;
    void DFS(TreeNode* root, int depth)
    {
        if(not root) return;
        if(not visited[depth]) store[depth] = root->val;
        else store[depth] = max(store[depth], root->val);
        visited[depth] = true;
        DFS(root->left, depth + 1);
        DFS(root->right, depth + 1);
    }
    vector<int> largestValues(TreeNode* root) 
    {
        DFS(root, 0);
        vector<int> ans(store.size());
        for(auto [depth, value] : store)
            ans[depth] = value;
        return ans;
    }
};