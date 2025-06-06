class Solution {
public:
    string robotWithString(string s) 
    {
        int n = s.size();
        auto minChar = s.back();
        vector<char> minToRight(n);

        for(int i = n - 1; i >= 0; i--)
        {
            minChar = min(minChar, s[i]);
            minToRight[i] = minChar;
        }

        string paper, store;
        for(int i = 0; i < n; i++)
        {
            store += s[i];
            auto minChar = i < n - 1 ? minToRight[i + 1] : s[i];
            while(store.size() and store.back() <= minChar)
            {
                paper += store.back();
                store.pop_back();
            }
        }
        reverse(begin(store), end(store));
        return paper + store;  
    }
};