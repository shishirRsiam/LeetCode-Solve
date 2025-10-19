class Solution {
public:
    unordered_set<string> seen;
    string findLexSmallestString(string s, int a, int b) 
    {
        if(seen.count(s)) return s;
        seen.insert(s);

        string op1 = s, op2;
        int reverse_count = b, n = op1.size();;
        for(int i = 1; i < n; i += 2)
            op1[i] = (op1[i] - '0' + a) % 10 + '0';
            
        while(reverse_count-- and s.size())
        {
            op2 += s.back();
            s.pop_back();
        }
        reverse(begin(op2), end(op2));
        op2 += s;

        return min(findLexSmallestString(op1, a, b), findLexSmallestString(op2, a, b));
    }
};