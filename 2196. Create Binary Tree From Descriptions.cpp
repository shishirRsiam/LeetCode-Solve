class Solution {
public:
    map<int,vector<pair<int,int>>> store;
    void constructTree(TreeNode* node)
    {
        if(!node or store.find(node->val) == store.end()) return;

        for(auto child:store[node->val])
        {
            TreeNode* childNode = new TreeNode(child.first);
            if(child.second) node->left = childNode;
            else node->right = childNode;
            constructTree(childNode);
        }
    }
    TreeNode* createBinaryTree(vector<vector<int>>& des) 
    {
        map<int, int>count;
        for(auto dir:des)
        {
            int parent = dir[0], val = dir[1], isLeft = dir[2];
            if(not count[parent]) count[parent]++;
            count[val]++, count[val]++;
            store[parent].push_back({val, isLeft});
        }

        TreeNode* root = NULL;
        for(auto [val, key]:count)
        {
            if(key == 1)
            {
                root = new TreeNode(val);
                break;
            }
        }
        constructTree(root);
        return root;
    }
};