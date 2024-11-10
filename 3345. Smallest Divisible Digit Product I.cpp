class Solution {
public:
    int smallestNumber(int n, int t) 
    {
        for(int i = n; i < 101; i++)
        {
            n = i;
            string s = to_string(i);
            int product = 1;
            for(auto ch : s)
                product *= (ch - '0');

            if(product % t == 0)
                break;
        }
        return n;
    }
};


