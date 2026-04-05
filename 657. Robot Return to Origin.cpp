class Solution {
public:
    bool judgeCircle(string moves) 
    {
        int start = 0, end = 0;
        for(char c:moves)
        {
            if(c == 'R') end++;
            else if(c == 'L')end--;
            else if(c == 'U') start--;
            else if(c == 'D') start++;
        }
        return start == 0 and end == 0;
    }
};