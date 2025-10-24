class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) 
    {
        vector<int> ans;
        int n = grid.size(), m = grid[0].size();
        for(int j = 0; j < m; j++)
        {
            int max_lenth = 0;
            for(int i = 0; i < n; i++)
                max_lenth = max(max_lenth, int(to_string(grid[i][j]).size()));
            ans.push_back(max_lenth);
        }
        return ans;    
    }
};