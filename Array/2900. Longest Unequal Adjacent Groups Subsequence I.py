class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) 
    {
        vector<string> ans;
        int i = 0, n = words.size();
        while(i < n)
        {
            ans.push_back(words[i]);
            while(i < n - 1 and groups[i] == groups[i + 1]) 
                i++;
            i++;
        }
        return ans;
    }
};