class Solution
{
public:
    vector<int> store;
    void help(ListNode *head)
    {
        while (head and head->next)
        {
            store.push_back(__gcd(head->val, head->next->val));
            head = head->next;
        }
    }
    ListNode *insertGreatestCommonDivisors(ListNode *head)
    {
        help(head);

        int cur = 0, val;
        bool flag = true;
        ListNode *ans = new ListNode(0);
        ListNode *tail = ans;
        while (head)
        {
            if (flag)
                val = head->val, head = head->next;
            else
                val = store[cur++];

            tail->next = new ListNode(val);
            tail = tail->next;
            flag = not flag;
        }
        return ans->next;
    }
};