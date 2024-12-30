class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) 
    {
        vector<int> ans;
        string s = to_string(k);
        int n = num.size(), idx = s.size() - 1, carry = 0;
        for(int i = n - 1; i >= 0; i--)
        {
            int val = carry + num[i];
            if(idx >= 0) val += (s[idx--] - '0');
            if(val >= 10) val -= 10, carry = 1;
            else carry = 0;
            ans.push_back(val);
        }    
        while(idx >= 0)
        {
            int val = carry + (s[idx--] - '0');
            if(val >= 10) val -= 10, carry = 1;
            else carry = 0;
            ans.push_back(val);
        }
        if(carry) ans.push_back(carry);
        reverse(begin(ans), end(ans));
        return ans;
    }
};