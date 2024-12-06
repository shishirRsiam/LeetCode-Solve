class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) 
    {
        long ans = 0, sum = 0;
        unordered_set<int>ban(begin(banned), end(banned));
        for(int i = 1; i <= n; i++)
        {
            if(ban.count(i)) continue;
            if(maxSum < sum + i) break;
            
            ans += 1, sum += i;
        }
        return ans;   
    }
};