class Solution {
public:
    void maxGainPoint(int &ans, int point, string &s, string target)
    {
        stack<char> st;
        for (auto ch : s)
        {
            if (!st.empty() and st.top() == target[0] and ch == target[1])
            {
                ans += point;
                st.pop();
            }
            else st.push(ch);
        }
        
        s.clear();
        while (!st.empty())
        {
            s += st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());
    }

    int maximumGain(string s, int x, int y)
    {
        int ans = 0;
        if (x > y) maxGainPoint(ans, x, s, "ab"), maxGainPoint(ans, y, s, "ba");
        else maxGainPoint(ans, y, s, "ba"), maxGainPoint(ans, x, s, "ab");
        return ans;
    }
};