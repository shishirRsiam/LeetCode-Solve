class Solution {
public:
    int possibleStringCount(string word) 
    {
        int ans = 1, count = 0, n = word.size();
        for(int i = 1; i <= n; i++)
        {
            if(word[i] == word[i - 1]) count += 1;
            else ans += count, count = 0;
        }    
        return ans;
    }
};


class Solution {
public:
    int possibleStringCount(string word) 
    {
        int ans = 1;
        unordered_map<char, int>count;    
        unordered_map<char, vector<int>>idx;
        for(int i = 0; i < word.size(); i++)
        {
            auto ch = word[i];
            if(idx[ch].empty() or idx[ch].back() + 1 == i)
            {
                count[ch] += 1; 
                if(count[ch] > 1) ans += 1;
            }
            idx[ch].push_back(i); 
        }
        return ans;
    }
};