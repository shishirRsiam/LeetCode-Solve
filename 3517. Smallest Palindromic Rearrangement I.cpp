class Solution {
public:
    string smallestPalindrome(string s) 
    {
        vector<int> count(26);
        for(auto &ch : s) count[ch - 'a'] += 1;

        int cur = 0, n = s.size();
        for(int i = 0; i < 26; i++)
        {
            if(count[i] % 2) s[n / 2] = i + 'a';
            while(count[i] > 1)
            {
                s[cur] = i + 'a';
                s[n - cur - 1] = i + 'a';
                count[i] -= 2;
                cur += 1;
            }
        }   
        return s; 
    }
};