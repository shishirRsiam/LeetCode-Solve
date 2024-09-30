class Solution
{
public:
    int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2)
    {
        int ans = 0, v;
        unordered_set<int> store;
        unordered_set<int> st1(begin(arr1), end(arr1));
        unordered_set<int> st2(begin(arr2), end(arr2));
        for (auto val : st2)
        {
            string cur;
            string s = to_string(val);
            for (auto ch : s)
            {
                cur += ch;
                v = stoi(cur);
                if (not store.count(v))
                    store.insert(v);
            }
        }

        for (auto val : st1)
        {
            string s = to_string(val);
            string cur;
            for (auto ch : s)
            {
                cur += ch;
                v = stoi(cur);
                if (store.count(v))
                    ans = max(ans, int(cur.size()));
            }
        }
        return ans;
    }
};