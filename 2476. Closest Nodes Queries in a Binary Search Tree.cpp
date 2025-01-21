class Solution {
public:
    set<int> store;
    void DFS(TreeNode* root)
    {
        if(not root) return;
        store.insert(root->val);
        DFS(root->left), DFS(root->right);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) 
    {
        DFS(root);
        vector<vector<int>> ans;
        for(auto val : queries)
        {
            auto mini = store.lower_bound(val);
            auto maxi = mini;
            
            if(mini == store.begin())
            {
                if(*mini == val) ans.push_back({*mini, *maxi});
                else ans.push_back({-1, *maxi});
            }
            else 
            {
                if(*mini != val) mini--;
                if(maxi == store.end()) ans.push_back({*mini, -1});
                else ans.push_back({*mini, *maxi});
            }
        }
        return ans;    
    }
};