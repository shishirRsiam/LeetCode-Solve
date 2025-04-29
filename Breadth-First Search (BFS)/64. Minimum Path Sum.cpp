#define pi pair<int, int>
#define pii pair<int, pi>
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        int n = grid.size(), m = grid[0].size();
        vector<pi> dir = {{0, 1}, {1, 0}};

        vector<vector<int>> costs(n, vector<int>(m, INT_MAX));
        costs[0][0] = grid[0][0];

        priority_queue<pii, vector<pii>, greater<pii>> minHeap;
        minHeap.push({costs[0][0], {0, 0}});
        while(not minHeap.empty())
        {
            auto [cost, idx] = minHeap.top(); minHeap.pop();
            auto [i, j] = idx;
            for(auto [ii, jj] : dir)
            {
                auto ni = i + ii, nj = j + jj;
                if(ni < 0 or nj < 0 or ni == n or nj == m) continue;
                if(cost + grid[ni][nj] < costs[ni][nj])
                {
                    costs[ni][nj] = cost + grid[ni][nj];
                    minHeap.push({costs[ni][nj], {ni, nj}});
                }
            }
            if(i == n - 1 and j == m - 1) return cost;
        }

        return costs[n - 1][m - 1];
    }
};