class Solution {
public:
    int takeCharacters(string s, int k) 
    {
        unordered_map<char, int>count;
        for(auto ch : s)
            count[ch]++;
        
        if (count['a'] < k || count['b'] < k || count['c'] < k)
            return -1;

        int i = 0, j = 0, n = s.size(), middleWindow = 0;
        while(j < n)
        {
            count[s[j++]]--;
            while(i < j and (count['a'] < k or count['b'] < k or count['c'] < k))
            {
                count[s[i++]]++;
            }
            middleWindow = max(middleWindow, j - i);
        }
        return n - middleWindow;
    }
};