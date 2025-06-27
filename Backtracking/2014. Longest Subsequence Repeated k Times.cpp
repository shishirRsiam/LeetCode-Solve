class Solution {
public: 
    string ans;
    bool KReapeatString(string cur, string s, int k)
    {
        int count = 0, i = 0;
        for(auto &ch : s)
        {
            if(cur[i] == ch and ++i == cur.size()) 
            {
                count += 1, i = 0;
                if(count == k) return true;
            }
        }
        return false;
    }

    void dfs(string cur, string &s, string &chars, int &k)
    {
        if(cur.size() * k > s.size()) return;

        for(auto &ch : chars)
        {
            string next = cur + ch;
            if(KReapeatString(next, s, k))
            {
                if(ans.size() < next.size())
                    ans = next;
                else if(ans.size() == next.size())
                    ans = max(ans, next);
                dfs(next, s, chars, k); 
            }
        }  
    }
    string longestSubsequenceRepeatedK(string s, int k) 
    {
        unordered_map<char, int> count;
        for(auto &ch : s)
            count[ch] += 1;

        string chars;
        for(auto [ch, cnt] : count)
            if(k <= cnt) chars += ch;

        dfs("", s, chars, k);

        return ans;
    }
};