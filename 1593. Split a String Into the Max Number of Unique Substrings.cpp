class Solution {
public:
    void backtrack(int idx, int n, int &maxSplit, unordered_set<string>st, string &s)
    {
        if(idx == n) 
        {
            maxSplit = max(maxSplit, int(st.size()));
            return;
        }
        string temp;
        for(int i = idx; i < n; i++)
        {
            temp += s[i];
            if(not st.count(temp))
            {
                st.insert(temp);
                backtrack(i + 1, n, maxSplit, st, s);
                st.erase(st.find(temp));
            }
        } 
    }
    int maxUniqueSplit(string s) 
    {
        unordered_set<string>st;
        int maxSplit = 0, n = s.size();
        backtrack(0, n, maxSplit, st, s);
        return maxSplit;
    }
};