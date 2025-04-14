class Solution {
public:
    int minMoves(int target, int maxDoubles) 
    {
        int ans = 0;
        while(target)
        {
            if(target % 2) 
            {
                ans += 1, target -= 1;
                continue;
            }
            if(not maxDoubles) break;

            ans += 1, target /= 2;
            maxDoubles -= 1;
        }
        return ans + target - 1;
    }
};