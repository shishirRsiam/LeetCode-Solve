#define pi pair<int, int>
#define pii pair<int, pi>
class Solution {
public:
    bool isValid(int &i, int &j, int &n, int &m) {
        return i >= 0 and j >= 0 and i < n and j < m;
    }
    int Dijkstra(vector<vector<int>>& grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<pi>directions {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        vector<vector<int>>time(n, vector<int>(m, INT_MAX)), visited(n, vector<int>(m));
        time[0][0] = 0;

        priority_queue<pii, vector<pii>, greater<pii>>minHeap;
        minHeap.push({0, {0, 0}});

        while(!minHeap.empty())
        {
            auto [parentTime, idx] = minHeap.top();
            auto [i, j] = idx; minHeap.pop();

            if(visited[i][j]) continue;
            visited[i][j] = 1;

            for(auto [ii, jj] : directions)
            {
                int ci = i + ii, cj = j + jj;
                if(isValid(ci, cj, n, m))
                {
                    int nextTime;
                    if(grid[ci][cj] <= parentTime + 1) nextTime = parentTime + 1;
                    else if((grid[ci][cj] - parentTime) % 2) nextTime = grid[ci][cj]; // Odd
                    else nextTime = grid[ci][cj] + 1; // Even

                    if (nextTime < time[ci][cj]) 
                    {
                        time[ci][cj] = nextTime;
                        minHeap.push({nextTime, {ci, cj}});
                    }
                }
            }
        }

        return time.back().back();
    }
    int minimumTime(vector<vector<int>>& grid) 
    {
        if(grid[0][1] > 1 and grid[1][0] > 1) return -1;
        return Dijkstra(grid);
    }
};