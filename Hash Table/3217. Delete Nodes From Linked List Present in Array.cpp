class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) 
    {
        set<int>st;
        for(auto num:nums) st.insert(num);
        
        ListNode* ans = new ListNode(0);
        ListNode* tail = ans;
        while(head)
        {
            int val = head->val; head = head->next;
            if(not st.count(val))
            {
                tail->next = new ListNode(val);
                tail = tail->next;
            }
        }
        return ans->next;
    }
};