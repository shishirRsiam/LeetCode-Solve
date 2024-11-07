class Solution {
public:
    bool isBalanced(string num) 
    {
        map<int, int>mp;
        bool flag = true;
        for(auto ch:num)
        {
            mp[flag] += ch - '0';
            flag = !flag;
        }
        return mp[0] == mp[1];
    }
};