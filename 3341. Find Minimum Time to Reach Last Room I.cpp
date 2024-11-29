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
                if(ci < 0 or cj < 0 or ci >= n or cj >= m) continue;

                int nextTime = moveTime[ci][cj] + 1;
                if(moveTime[ci][cj] < parentTime + 1) nextTime = parentTime + 1;

                if(nextTime < time[ci][cj])
                {
                    time[ci][cj] = nextTime;
                    minHeap.push({nextTime, {ci, cj}});
                }
            }
        }
        
        return time.back().back();
    }
    int minTimeToReach(vector<vector<int>>& moveTime) 
    {
        return dijkstra(moveTime);
    }
};