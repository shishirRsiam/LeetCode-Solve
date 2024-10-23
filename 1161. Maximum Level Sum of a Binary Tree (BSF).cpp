class Solution {
public:
    int maxLevelSum(TreeNode* root) 
    {
        queue<TreeNode*>q;
        q.push(root);
        int ans = 1, depth = 1, size, maxSum = root->val, sum;
        while(!q.empty())
        {
            sum = 0, size = q.size();
            while(size--)
            {
                auto node = q.front(); q.pop();
                sum += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(sum > maxSum)
            {
                maxSum = sum;
                ans = depth;
            }
            depth += 1;
        }
        return ans;
    }
};