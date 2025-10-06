using tpl = tuple<int, int, int>;
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) 
    {
        int ans = INT_MIN, n = grid.size();

        priority_queue<tpl, vector<tpl>, greater<tpl>> minHeap;
        vector<vector<bool>> visited(n + 1, vector<bool>(n + 1));
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        visited[0][0] = true;
        minHeap.push({grid[0][0], 0, 0});
        while(not minHeap.empty())
        {
            auto [val, i, j] = minHeap.top(); minHeap.pop();
            ans = max(ans, val);
            if(i == n - 1 and j == n - 1) return ans;

            for(auto &[ii, jj] : directions)
            {
                auto ni = i + ii, nj = j + jj;
                if(ni < 0 or nj < 0 or ni == n or nj == n or visited[ni][nj])
                    continue;

                visited[ni][nj] = true;
                minHeap.push({grid[ni][nj], ni, nj});
            }
        }
        return -1;
    }
};