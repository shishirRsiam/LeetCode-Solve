class Solution {
public:
    bool hasAlternatingBits(int n)
    {
        vector<int> b;
        while(n > 0)
        {
            int tmp = n % 2;
            b.insert(b.begin(), tmp);
            n /= 2;
        }
        int sz = b.size();
        for(int i = 0; i < sz - 1; i++)
            if(b[i] == b[i + 1])
                return false;
        return true;
    }
};