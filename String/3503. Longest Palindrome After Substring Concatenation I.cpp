class Solution {
    public:
        auto isPalindrome(string s)
        {
            int i = 0, j = s.size() - 1;
            while(i < j)
                if(s[i++] != s[j--]) return false;
            return true;
        }
        auto allSubstring(string &s)
        {
            int n = s.size();
            vector<string> allSubstr;
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    string temp;
                    for(int k = i; k <= j; k++)
                        temp += s[k];
                    allSubstr.push_back(temp);
                }
            }
            return allSubstr;
        }
        int longestPalindrome(string s, string t) 
        {
            int ans = 0;
            auto allSubstrS = allSubstring(s);
            auto allSubstrT = allSubstring(t);
            for(auto &s1 : allSubstrS)
            {
                for(auto &s2 : allSubstrT)
                {
                    if(isPalindrome(s1 + s2))
                        ans = max(ans, int(s1.size() + s2.size()));
                    if(isPalindrome(s1))
                        ans = max(ans, int(s1.size()));
                    if(isPalindrome(s2))
                        ans = max(ans, int(s2.size()));
                }
            }
            return ans;
        }
    };