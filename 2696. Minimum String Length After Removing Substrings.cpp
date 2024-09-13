class Solution
{
public:
    int minLength(string s)
    {
        stack<char> st;
        for (auto ch : s)
        {
            if (!st.empty())
            {
                if (st.top() == 'A' and ch == 'B')
                {
                    st.pop();
                    continue;
                }
                if (st.top() == 'C' and ch == 'D')
                {
                    st.pop();
                    continue;
                }
            }
            st.push(ch);
        }
        return st.size();
    }
};