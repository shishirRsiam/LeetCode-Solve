class Solution {
public:
    int nextBeautifulNumber(int n) 
    {
        if(n > 666665) return 1224444;
        
        for(int i = n + 1; i < 1224450; i++)
        {
            string s = to_string(i);

            unordered_map<int, int> count;
            for(auto &ch : s)
                count[ch - '0'] += 1;

            bool isBalanced = true;
            for(auto &[val, cnt] : count)
            {
                if(val != cnt)
                {
                    isBalanced = not isBalanced;
                    break;
                }
            }
            if(isBalanced) return i;
        }    
        return -1;
    }
};