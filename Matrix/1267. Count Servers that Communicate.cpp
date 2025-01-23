// 1267. Count Servers that Communicate (PODT: January 22, 2025)

class Solution {
public:
    int countServers(vector<vector<int>>& grid) 
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> store(2, vector<int>(255));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                store[0][i] += grid[i][j], store[1][j] += grid[i][j];

        int ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                ans += grid[i][j] and (store[0][i] > 1 or store[1][j] > 1);

        return ans;    
    }
};

// Submission Date: January 22, 2025. Code contains 17 lines.