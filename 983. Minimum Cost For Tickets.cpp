class Solution {
public:
    int solve(int &n, vector<int>& days, vector<int>& costs, int idx, vector<int> &memo)
    {
        if(idx == n) return 0;
        if(memo[idx] != -1) return memo[idx];

        int one_days_pass = costs[0] + solve(n, days, costs, idx + 1, memo);

        int i = idx;
        while(i < n and days[i] < days[idx] + 7) i++;
        int seven_days_pass = costs[1] + solve(n, days, costs, i, memo);

        while(i < n and days[i] < days[idx] + 30) i++;
        int thurty_days_pass = costs[2] + solve(n, days, costs, i, memo);

        return memo[idx] = min({one_days_pass, seven_days_pass, thurty_days_pass});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) 
    {
        int n = days.size();
        vector<int> memo(n, -1);
        return solve(n, days, costs, 0, memo);
    }
};