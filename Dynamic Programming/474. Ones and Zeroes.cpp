class Solution {
public:
    int memo[605][105][105];
    auto solve(int cur, vector<pair<int, int>> &store, int n, int m)
    {
        if(n < 0 or m < 0) return 0;
        if(cur == store.size()) 
        {
            if(n < 0 or m < 0) return 0;
            return 1;
        }

        int &gain = memo[cur][n][m];
        if(gain != -1) return gain;

        auto [zero, one] = store[cur];
        int pic = solve(cur + 1, store, n - one, m - zero) + 1;
        int not_pic = solve(cur + 1, store, n, m);

        return gain = max(pic, not_pic);
    }
    int findMaxForm(vector<string>& strs, int m, int n) 
    {
        vector<pair<int, int>> store;
        for(auto &s : strs)
        {
            int one = 0, zero = 0;
            for(auto &ch : s)
                ch == '1' ? one++ : zero++;
            store.push_back({zero, one});
        }

        memset(memo, -1, sizeof(memo));
        return solve(0, store, n, m) - 1;
    }
};