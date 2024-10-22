class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) 
    {
        long sum, size;
        vector<long>store;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            sum = 0, size = q.size();
            for(int i = 0; i < size; i++)
            {
                auto node = q.front(); q.pop();
                sum += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            store.push_back(sum);
        }
        
        if(store.size() < k) return -1;
        sort(rbegin(store), rend(store));
        return store[k - 1];
    }
};