class Solution {
public:
    int pairSum(ListNode* head) 
    {
        vector<long long>v;
        while(head)
        {
            v.push_back(head->val);
            head = head->next;
        }
        long long ans = 0;
        int i = 0, j = v.size()-1;
        while(i<j)
        {
            ans = max(ans, v[i]+v[j]);
            i++, j--;
        }
        return ans;
    }
};