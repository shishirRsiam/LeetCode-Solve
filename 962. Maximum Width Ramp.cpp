class Solution
{
public:
    int maxWidthRamp(vector<int> &nums)
    {
        int n = nums.size();

        stack<int> st;
        st.push(0);
        for (int i = 1; i < n; i++)
            if (nums[i] < nums[st.top()])
                st.push(i);

        int ans = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            while (st.size() and nums[st.top()] <= nums[i])
            {
                ans = max(ans, i - st.top());
                st.pop();
            }
        }
        return ans;
    }
};