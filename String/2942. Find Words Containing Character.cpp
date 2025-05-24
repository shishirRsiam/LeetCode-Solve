class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) 
    {
        vector<int> ans;
        int n = words.size();
        for(int i = 0; i < n; i++)
        {
            unordered_set<char>st(begin(words[i]), end(words[i]));
            if(st.count(x)) ans.push_back(i);
        }
        return ans;    
    }
};