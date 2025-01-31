class Solution {
public:
    bool isValid(int &i, int &j, int n) {
        return (i >= 0 and j >= 0 and i < n and j < n);
    }

    int groupNumber = 0;
    unordered_map<int, int> ump;
    vector<vector<int>> storeGroup;
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited)
    {
        if(not isValid(i, j, grid.size())) return;
        if(visited[i][j] or not grid[i][j]) return;

        ump[groupNumber] += 1;
        storeGroup[i][j] = groupNumber;

        visited[i][j] = true;
        dfs(i + 1, j, grid, visited), dfs(i - 1, j, grid, visited);
        dfs(i, j + 1, grid, visited), dfs(i, j - 1, grid, visited);
    }
    int largestIsland(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        bool fountZero = false;
        storeGroup.resize(n, vector<int>(n));
        vector<vector<bool>> visited(n, vector<bool>(n));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(not grid[i][j]) fountZero = true;
                if(grid[i][j] and not visited[i][j])
                {
                    groupNumber += 1;
                    dfs(i, j, grid, visited);
                }
            }
        }
        if(not fountZero) return n * n;

        int ans = 0;
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(not grid[i][j])
                {
                    unordered_set<int> group;
                    for(auto [ii, jj] : dir)
                    {
                        int ci = i + ii, cj = j + jj;
                        if(isValid(ci, cj, n) and grid[ci][cj])
                        {
                            if(not group.count(storeGroup[ci][cj]))
                                group.insert(storeGroup[ci][cj]);
                        }
                    }

                    int sum = 1;
                    for(auto cnt : group) sum += ump[cnt];
                    ans = max(ans, sum);
                }
            }
        }
        return ans;
    }
};