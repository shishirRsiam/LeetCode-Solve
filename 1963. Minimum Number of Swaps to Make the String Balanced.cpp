class Solution
{
public:
    int minSwaps(string s)
    {
        stack<char> st;
        int count = 0;
        for (char c : s)
        {
            if (c == '[')
                st.push(c);
            else
            {
                if (st.empty())
                    count++;
                else
                    st.pop();
            }
        }
        int ans = count / 2;
        if (count % 2)
            ans++;
        return ans;
    }
};