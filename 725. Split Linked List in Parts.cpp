class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) 
    {
        // Initialize a vector to store values from the linked list
        vector<int> value;

        // Traverse through the linked list and store each node's value in the 'value' vector
        while (head) 
        {
            value.push_back(head->val); // Add the current node's value to the vector
            head = head->next; // Move to the next node
        }

        // 'n' is the total number of nodes in the linked list
        int n = value.size(), cur = 0;

        // 'need' is the base number of elements each part should have
        int need = n / k;

        // 'extra' is the number of parts that need one more element
        int extra = n % k;

        // Initialize the result vector of ListNode pointers
        vector<ListNode*> ans;

        // Split the list into 'k' parts
        while (k--)
        {
            // Create a dummy node to make it easier to build the linked list part
            ListNode* head = new ListNode(0);
            ListNode* tail = head; // Tail will be used to append nodes to this new part
            
            // Add 'need' nodes to the current part
            int i = cur, cnt = need;

            // Add 'need' number of nodes to the current part if available
            while (cnt-- && i < n)
            {
                tail->next = new ListNode(value[i++]); // Append the current node
                tail = tail->next; // Move the tail pointer to the newly added node
                if (cnt == 0) break; // Stop if we've added the required nodes
            }

            // If there are extra nodes left, add one more node to this part
            if (extra)
            {
                extra--; // Reduce the count of extra nodes
                tail->next = new ListNode(value[i++]); // Add one extra node to the current part
            }

            // Update 'cur' to the next position in the 'value' vector
            cur = i;

            // Add the newly created linked list part (excluding the dummy node) to the result vector
            ans.push_back(head->next);
        }

        // Return the vector containing the parts
        return ans;
    }
};