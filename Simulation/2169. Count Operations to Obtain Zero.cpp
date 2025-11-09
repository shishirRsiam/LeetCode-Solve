class Solution {
public:
    int countOperations(int a, int b) 
    {
        if(!a or !b) return 0;

        int cnt = 0;
        while(a != 0)
        {
            if(a>=b) a-= b;
            else b -= a;
            cnt++;
        }
        return cnt;
    }
};