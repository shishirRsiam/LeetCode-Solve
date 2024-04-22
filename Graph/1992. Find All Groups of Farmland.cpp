class Solution {
public:
    int n, m;
    vector<vector<int>>land;
    void dfs(int i, int j, int &endRow, int &endCol)
    {
        if(i<0 or j<0 or i>=n or j>=m or !land[i][j]) return;
        land[i][j] = 0;
        endRow = max(endRow, i), endCol = max(endCol, j);
        dfs(i+1, j, endRow, endCol), dfs(i-1, j, endRow, endCol), 
        dfs(i, j+1, endRow, endCol), dfs(i, j-1, endRow, endCol);
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& input) 
    {
        vector<vector<int>>ans;
        land = input, n = land.size(), m = land[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(land[i][j])
                {
                    int endRow = 0, endCol = 0;
                    dfs(i, j, endRow, endCol);
                    ans.push_back({i, j, endRow, endCol});
                }
            }
        }
        return ans;
    }
};