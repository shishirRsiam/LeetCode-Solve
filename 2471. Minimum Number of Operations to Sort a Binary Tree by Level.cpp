class Solution {
public:
    int minimumSwaps(vector<int> &arr)
    {
        int n = arr.size();
        vector<pair<int, int>> store;
        for(int i = 0; i< n; i++)
            store.push_back({arr[i], i});
        sort(begin(store), end(store));

        int swaps = 0;
        vector<bool> visited(n);
        for(int i = 0; i < n; i++)
        {
            if(visited[i] or i == store[i].second) continue;

            int cycle_count = 0, x = i;
            while(not visited[x])
            {
                cycle_count += 1;
                visited[x] = true;
                x = store[x].second;
            }
            swaps += cycle_count - 1;
        }
        return swaps;
    }
    int minimumOperations(TreeNode* root) 
    {
        int minSwaps = 0;
        queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty())
        {
            vector<int> arr;
            int size = queue.size();
            while(size--)
            {
                auto node = queue.front(); queue.pop();
                arr.push_back(node->val);
                
                if(node->left) queue.push(node->left);
                if(node->right) queue.push(node->right);
            }
            minSwaps += minimumSwaps(arr);
        }
        return minSwaps;
    }
};