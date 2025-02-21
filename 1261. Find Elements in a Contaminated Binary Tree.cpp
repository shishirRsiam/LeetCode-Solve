class FindElements {
    public:
        unordered_set<int> store;
        void DFS(TreeNode* &root, int val)
        {
            if(not root) return;
            store.insert(val);
            DFS(root->left, val * 2 + 1);
            DFS(root->right, val * 2 + 2);
        }
        FindElements(TreeNode* root) {
            store.insert(0);
            DFS(root->left, 1);
            DFS(root->right, 2);
        }
        
        bool find(int target) {
            return store.count(target);
        }
    };