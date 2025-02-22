class Solution {
    public:
        int cur = 0;
        vector<int> idx;
        unordered_map<int, queue<int>> store;
        TreeNode* DFS(int depth)
        {
            if(store[depth].empty()) return NULL;
            
            TreeNode* root = new TreeNode(store[depth].front());
            store[depth].pop();
    
            cur++;
            
            if(cur < idx.size() and idx[cur] == depth + 1) 
                root->left = DFS(depth + 1);
            if(cur < idx.size() and idx[cur] == depth + 1) 
                root->right = DFS(depth + 1);
    
            return root;
        }
        TreeNode* recoverFromPreorder(string traversal) 
        {
            string num;
            int count = 0, i = 0, n = traversal.size();
            while(i < n)
            {
                count = 0, num = "";
                while(traversal[i] == '-') count += 1, i += 1;
    
                while(isdigit(traversal[i])) num += traversal[i++];
    
                idx.push_back(count);
                store[count].push(stoi(num));
            }
            return DFS(0);
        }
    };