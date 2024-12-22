class Solution {
public:
    bool isSameAfterReversals(int num) 
    {
        string reverseNum = to_string(num);
        reverse(reverseNum.begin(), reverseNum.end());
        reverseNum = to_string(stoi(reverseNum));
        reverse(reverseNum.begin(), reverseNum.end());
        return num == stoi(reverseNum);
    }
};