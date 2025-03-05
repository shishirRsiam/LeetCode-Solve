class Solution {
    public:
        int numberOfCuts(int n) 
        {
            return (n > 1 and n % 2) ? n : n / 2;    
        }
    };