class Solution {
public:
    vector<vector<int>> visited, grid;
    int dfs(int i, int j)
    {
        if(i < 0 or j < 0 or i == grid.size() or j == grid[0].size()) return 0;
        if(visited[i][j] or (not grid[i][j])) return 0;
        
        visited[i][j] = 1;
        int currentFish = grid[i][j];
        return currentFish + dfs(i + 1, j) + dfs(i - 1, j) + dfs(i, j + 1) + dfs(i, j - 1);
    }
    int findMaxFish(vector<vector<int>>& matrix) 
    {
        int n = matrix.size(), m = matrix[0].size();

        grid = matrix;
        visited.resize(n, vector<int>(m));

        int maxFishCollect = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(grid[i][j] and not visited[i][j])
                    maxFishCollect = max(maxFishCollect, int(dfs(i, j)));

        return maxFishCollect;
    }
};