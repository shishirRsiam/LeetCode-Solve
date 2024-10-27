class Solution {
public:
    unordered_map<int, int> nodeDepth; 
    unordered_map<int, int> nodeHeight; 
    unordered_map<int, vector<int>> levelHeights;

    int DFS(TreeNode* node, int depth) {
        if (!node) return -1;
        
        int leftHeight = DFS(node->left, depth + 1);
        int rightHeight = DFS(node->right, depth + 1);
        int currentHeight = 1 + max(leftHeight, rightHeight);
        
        nodeDepth[node->val] = depth;
        nodeHeight[node->val] = currentHeight;
        levelHeights[depth].push_back(currentHeight);
        
        return currentHeight;
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        DFS(root, 0);
        
        for (auto& [depth, heights] : levelHeights) 
            sort(heights.rbegin(), heights.rend());

        vector<int> ans;
        int originalTreeHeight = nodeHeight[root->val];

        for (int query : queries) 
        {
            int queryDepth = nodeDepth[query];
            int queryHeight = nodeHeight[query];
            
            int maxRemainingHeight = levelHeights[queryDepth][0];;
            if (levelHeights[queryDepth][0] == queryHeight) 
            {
                if (levelHeights[queryDepth].size() > 1) 
                    maxRemainingHeight = levelHeights[queryDepth][1];
                else maxRemainingHeight = -1; 
            } 

            int newTreeHeight = (queryDepth + maxRemainingHeight);
            ans.push_back(newTreeHeight);
        }
        
        return ans;
    }
};
