class Solution {
    public:
        bool hasSameDigits(string s) 
        {
            int n = s.size();
            while(n > 2)
            {
                string temp;
                for(int i = 1; i < n; i++)
                    temp += to_string(((s[i] - '0') + (s[i - 1] - '0')) % 10);
                s = temp;
                n = s.size();
            }
            return s[0] == s[1];
        }
    };