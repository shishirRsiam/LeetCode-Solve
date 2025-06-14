class Solution {
public:
    int minMaxDifference(int num) 
    {
        string s = to_string(num);
        
        char changeChar = '9';
        for(auto &ch : s)
        {
            if(ch == '9') continue;
            changeChar = ch;
            break;
        }

        auto s1 = s, s2 = s;
        for(auto &ch : s1)
            ch = (ch ==  changeChar ? '9' : ch);
        for(auto &ch : s2)
            ch = (ch ==  s[0] ? '0' : ch);

        return stoi(s1) - stoi(s2);  
    }
};