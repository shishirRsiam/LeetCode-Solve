#define pi pair<int, int>
#define pii pair<int, pi>
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        if(grid[0][0]) return -1;

        int n = grid.size();
        vector<vector<int>> distance(n, vector<int>(n, INT_MAX));
        priority_queue<pii, vector<pii>, greater<pii>> minHeap;

        grid[0][0] = true;
        distance[0][0] = 1;
        minHeap.push({1, {0, 0}});

        vector<pi> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {1, -1}, {-1, 1}, {1, 1}};
        while(not minHeap.empty())
        {
            auto [cost, idx] = minHeap.top(); minHeap.pop();
            auto [i, j] = idx;

            for(auto [ii, jj] : dir)
            {
                int ni = i + ii, nj = j + jj;
                if(ni < 0 or nj < 0 or ni == n or nj == n or grid[ni][nj]) continue;

                if(cost + 1 < distance[ni][nj])
                {
                    grid[ni][nj] = true;
                    distance[ni][nj] = cost + 1;
                    minHeap.push({distance[ni][nj], {ni, nj}});
                }
                if(ni == n - 1 and nj == n - 1) return distance[ni][nj];
            }
        }

        return distance[n - 1][n - 1] == INT_MAX ? -1 : distance[n - 1][n - 1]; 
    }
};