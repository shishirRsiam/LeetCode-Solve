#define pi pair<int, int>
#define pii pair<int, pi>
class Solution {
public:
    int dijkstra(vector<vector<int>>& moveTime)
    {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<pi>directions {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        vector<vector<bool>>visited(n, vector<bool>(m));
        vector<vector<int>>time(n, vector<int>(m, INT_MAX));
        time[0][0] = moveTime[0][0];

        vector<vector<int>>steps(n, vector<int>(m));
        steps[0][0] = 1;

        priority_queue<pair<int, pi>, vector<pair<int, pi>>, greater<pair<int, pi>>>minHeap;
        minHeap.push({0, {0, 0}});

        while(!minHeap.empty())
        {
            auto [parentTime, idx] = minHeap.top(); minHeap.pop();
            auto [i, j] = idx;

            if(visited[i][j]) continue;
            visited[i][j] = true;

            for(auto [ii, jj] : directions)
            {
                int ci = i + ii, cj = j + jj;
                if(ci < 0 or cj < 0 or ci == n or cj == m) continue;
                
                int addTime = ((steps[i][j]) % 2) ? 1 : 2;
                int nextTime = max(parentTime, moveTime[ci][cj]) + addTime;

                if(nextTime < time[ci][cj])
                {
                    time[ci][cj] = nextTime;
                    steps[ci][cj] = steps[i][j] + 1;
                    minHeap.push({nextTime, {ci, cj}});
                }
            }
            if(i == n - 1 and j == m - 1) break;
        }
        
        return time.back().back();
    }
    int minTimeToReach(vector<vector<int>>& moveTime) 
    {
        return dijkstra(moveTime);
    }
};