class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) 
    {
        vector<int>count(1e5+5);
        for(auto val:costs) count[val]++;
        
        int ans = 0, cnt, cost;
        for(int i=1;i<1e5+5;i++)
        {
            cnt = count[i];
            if(cnt)
            {
                int buyCount = min(coins/i, cnt);
                ans += buyCount;
                coins -= i*long(cnt);
            }
            if (coins <= 0) break;
        }
        return ans;
    }
};