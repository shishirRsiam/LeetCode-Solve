class Solution {
public:
    int minOperations(vector<int>& nums) 
    {
        int ans = 0;
        stack<int> st;
        for(auto &val : nums)
        {
            while(not st.empty() and st.top() > val)
                st.pop();

            if(val and (st.empty() or val != st.top()))
            {
                ans += 1;
                st.push(val);
            }
        }
        return ans;    
    }
};