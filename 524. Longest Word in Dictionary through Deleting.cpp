class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) 
    {
        string ans;
        int m = s.size();
        for(auto &dict : dictionary)
        {
            if(dict.size() > s.size()) continue;

            int i = 0, j = 0, n = dict.size();
            while(i < n and j < m)
            {
                if(dict[i] == s[j]) i += 1;
                j += 1;
            }

            if(i == n)
            {
                if(ans.size() == dict.size())
                        ans = min(ans, dict);
                else if(ans.size() < dict.size())
                        ans = dict;
            }
        }
        return ans;
    }
};