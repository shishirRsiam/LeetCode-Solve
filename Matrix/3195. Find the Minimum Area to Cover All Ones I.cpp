class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) 
    {
        int maxRow = -1, maxCol = -1;
        int minRow = 1e9, minCol = 1e9;
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j])
                {
                    minRow = min(minRow, i);
                    minCol = min(minCol, j);
                    maxRow = max(maxRow, i);
                    maxCol = max(maxCol, j);
                }
            }
        }
        
        int ans = 0;
        for(int i = minRow; i <= maxRow; i++)
            for(int j = minCol; j <= maxCol; j++)
                ans += 1;
        return ans;   
    }
};