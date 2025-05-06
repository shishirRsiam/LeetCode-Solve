class Solution {
public:
    int maxProduct(int n) 
    {
        auto s = to_string(n);
        sort(begin(s), end(s));
        return ((s[s.size() - 1] - '0') * (s[s.size() - 2] - '0')); 
    }
};