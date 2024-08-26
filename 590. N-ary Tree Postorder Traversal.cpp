class Solution {
public:

    vector<int>a;

    void postOrder(Node* root)
    {
        if(root == NULL) return;
        for(Node* child: root->children)
            postOrder(child);
        a.push_back(root->val);
    }
    vector<int> postorder(Node* root) 
    {
        postOrder(root);
        return a;
    }
};