class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) 
    {
        if(k == 1) return 'a';

        int n = operations.size();
        long long len = 1, operationType;
        for(int i = 0; i < n; i++)
        {
            len += len;
            if(len >= k)
            {
                operationType = operations[i];
                break;
            }
        }
        char ch = kthCharacter(k - len/2, operations);

        if(not operationType) return ch;
        return ch == 'z' ? 'a' : ch + 1;
    }
};