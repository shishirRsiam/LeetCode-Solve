class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) 
    {
        int ans = numBottles, count = 0, curBottles = 0;
        while(true)
        {
            if(numBottles - numExchange < 0)
            {
                numBottles += curBottles;
                ans += count;
                count = curBottles = 0;
            }
            if(numBottles - numExchange < 0) break;
            count++, curBottles++;
            numBottles -= numExchange;
        }
        return ans;
    }
};