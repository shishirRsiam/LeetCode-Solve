#define pi pair<int, int>
class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) 
    {
        int q = queries.size(), n = grid.size(), m = grid[0].size();

        vector<pi> store;
        for(int i = 0; i < q; i++)
            store.push_back({queries[i], i});
        sort(begin(store), end(store));

        vector<int> ans(q);
        vector<vector<bool>> visited(n, vector<bool>(m));
        priority_queue<pair<int, pi>, vector<pair<int, pi>>, greater<pair<int, pi>>> minHeap;

        int count = 0;
        visited[0][0] = true;
        minHeap.push({grid[0][0], {0, 0}});
        vector<pi> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for(auto [queri, index] : store)
        {
            while(not minHeap.empty() and minHeap.top().first < queri)
            {
                count += 1;
                auto [val, idx] = minHeap.top(); minHeap.pop();
                auto [i, j] = idx;
                for(auto [ii, jj] : dir)
                {
                    int ni = i + ii, nj = j + jj;
                    if(ni < 0 or nj < 0 or ni == n or nj == m or visited[ni][nj]) continue;
                    visited[ni][nj] = true;
                    minHeap.push({grid[ni][nj], {ni, nj}});
                }
            }
            ans[index] = count;
        }
        
        return ans;
    }
};