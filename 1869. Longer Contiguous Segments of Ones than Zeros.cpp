class Solution {
public:
    bool checkZeroOnes(string s) 
    {
        int count = 1, n = s.size();
        unordered_map<char, int>store;
        for(int i = 0; i < n; i++)
        {
            count += 1;
            if(s[i] != s[i + 1]) count = 1;
            store[s[i]] = max(store[s[i]], count);
        }
        return store['1'] > store['0'];
    }
};