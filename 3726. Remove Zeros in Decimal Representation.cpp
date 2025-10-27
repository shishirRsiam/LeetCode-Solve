class Solution {
public:
    long long removeZeros(long long n) 
    {
        string ans, s = to_string(n);
        for(auto &ch : s)
            if(ch != '0') ans += ch;
        return ans.size() ? stoll(ans) : 0;
    }
};