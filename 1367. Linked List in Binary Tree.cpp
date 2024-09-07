class Solution {
public:
    // This function checks if the current linked list path matches a path starting from the current binary tree node.
    bool checkPath(ListNode* head, TreeNode* root) 
    {
        if(!head) return true;  // If we reach the end of the linked list, it means we found the path, return true.
        if(!root or head->val != root->val) return false;  // If the binary tree node is null or the values don't match, return false.
        
        // Recursively check the next node in the linked list with both left and right children of the binary tree node.
        return checkPath(head->next, root->left) or checkPath(head->next, root->right);
    }

    bool isSubPath(ListNode* head, TreeNode* root) 
    {
        if(!root) return false;  // If the binary tree is empty, return false since there's no subpath possible.

        // Check if the current binary tree node matches the head of the linked list and starts a valid path.
        // If not, recursively check the left and right children to find a matching subpath.
        return (head->val == root->val && checkPath(head, root)) or 
               isSubPath(head, root->left) or
               isSubPath(head, root->right);
    }
};