#define pi pair<int, int>
#define pii pair<int, pi>
class Solution {
public:
    int minCost(vector<vector<int>>& grid) 
    {
        int n = grid.size(), m = grid[0].size();
        
        vector<pi> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<int>> distance(105, vector<int>(105, INT_MAX));
        distance[0][0] = 0;

        priority_queue<pii, vector<pii>, greater<pii>> minHeap;
        minHeap.push({0, {0, 0}});
        while(!minHeap.empty())
        {
            auto [parentCost, idx] = minHeap.top(); minHeap.pop();
            auto [i, j] = idx;
            if (parentCost > distance[i][j]) continue;

            for(int dir = 0; dir < 4; dir++)
            {
                auto [ii, jj] = direction[dir];
                int ci = ii + i, cj = jj + j;
                if(ci < 0 or ci == n or cj < 0 or cj == m) continue;

                int childCost = parentCost + (grid[i][j] != dir + 1);
                if(childCost < distance[ci][cj])
                {
                    distance[ci][cj] = childCost;
                    minHeap.push({distance[ci][cj], {ci, cj}});
                }
            }
        }

        return distance[n - 1][m - 1];
    }
};