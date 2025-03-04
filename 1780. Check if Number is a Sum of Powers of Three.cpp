class Solution {
    public:
        bool checkPowersOfThree(int n) 
        {
            int cur_pow = 15;
            while(cur_pow--)
            {
                if(pow(3, cur_pow) > n) continue;
                n -= pow(3, cur_pow);
            }
            return n == 0;    
        }
    };