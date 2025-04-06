class Solution {
public:
    int rotatedDigits(int n) 
    {
        unordered_map<char, char> changes;
        unordered_set<char> rotatedChar = {'0', '1', '2', '5', '6', '8', '9'};
        for(char ch = '0'; ch <= '9'; ch++) 
            changes[ch] = ch;
        changes['2'] = '5';
        changes['5'] = '2';
        changes['6'] = '9';
        changes['9'] = '6';

        int ans = 0;
        for(int i = 2; i <= n; i++)
        {
            string s = to_string(i), t = s;
            for(char &ch : t) ch = changes[ch];

            bool canRotate = s != t;
            for(auto &ch : t)
                if(not rotatedChar.count(ch))
                    canRotate = false;

            ans += canRotate;
        }
        return ans;    
    }
};