class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) 
    {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        int n = robot.size(), m = factory.size();
        vector<vector<long long>> memo(n + 1, vector<long long>(m + 1, -1));

        function<long(int, int)> solve = [&](int i, int j)
        {
            if (i >= n) return 0LL;
            if (j >= m) return LLONG_MAX / 2;
            if (memo[i][j] != -1) return memo[i][j];

            long cost = 0;
            long minDistance = solve(i, j + 1);
            int factoryPos = factory[j][0], limit = factory[j][1];

            for (int k = 0; k < limit && (i + k) < n; k++)
            {
                cost += abs(factoryPos - robot[i + k]);
                minDistance = min(minDistance, cost + solve(i + k + 1, j + 1));
            }

            return memo[i][j] = minDistance;
        };

        return solve(0, 0);
    }
};
