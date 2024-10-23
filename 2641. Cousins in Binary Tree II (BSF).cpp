class Solution {
public:
    int target1, target2;
    map<int, vector<int>>store;
    void solve(TreeNode* root, int depth)
    {
        if(!root) return;
        if(root->left)
        {
            if(root->left->val == target1 or root->left->val == target2)
            {
                store[depth].push_back(root->val);
            }
        }
        if(root->right)
        {
            if(root->right->val == target1 or root->right->val == target2)
            {
                store[depth].push_back(root->val);
            }
        }
        solve(root->left, depth + 1);
        solve(root->right, depth + 1);
    }
    bool isCousins(TreeNode* root, int x, int y) 
    {
        target1 = x, target2 = y;
        solve(root, 1);
        for(auto [depth, vec]:store)
        {
            int n = vec.size();
            for(int i = 0; i < n; i++)
            {
                for(int j = i + 1; j < n; j++)
                {
                    if(vec[i] != vec[j]) return true;
                }
            }
            cout<<"Depth "<<depth<<" -> "; 
            for(auto val:vec) cout<<val<<" ";
            cout<<endl;  
        }
        return false;
    }
};