class Solution {
public:
    unordered_map<int, long>store;
    void DFS(TreeNode* root, int depth)
    {
        if(!root) return;
        store[depth] += root->val;
        DFS(root->left, depth + 1);
        DFS(root->right, depth + 1);
    }
    long long kthLargestLevelSum(TreeNode* root, int k) 
    {
        DFS(root, 0);
        if(store.size() < k) return -1;

        vector<long> ans;
        for(auto [depth, sum] : store)
            ans.push_back(sum);
            
        sort(rbegin(ans), rend(ans));
        return ans[k - 1];
    }
};