class Solution {
public:
    int distMoney(int money, int children) 
    {
        int ans = 0;
        money -= children;
        while(money - 7 >= 0)
        {
            ans += 1;
            money -= 7;
            if(ans == children) break;
        }

        if(ans == children and money) ans -= 1;
        else if(ans + 1 == children and money == 3) ans -= 1;

        return money >= 0 ? ans : -1;
    }
};