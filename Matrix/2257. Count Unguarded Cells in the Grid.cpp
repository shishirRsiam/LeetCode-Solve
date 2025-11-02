class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) 
    {
        vector<vector<int>>mat(m, vector<int>(n));

        for(auto vec : walls)
            mat[vec[0]][vec[1]] = -2;
        for(auto vec : guards)
            mat[vec[0]][vec[1]] = -1;

        for(auto vec : guards)
        {
            int x = vec[0], y = vec[1];
            for(int i = y + 1; i < n; i++)
            {
                if(mat[x][i] == -2 or mat[x][i] == -1) break;
                mat[x][i] = 1;
            }
            for(int i = y - 1; i >= 0; i--)
            {
                if(mat[x][i] == -2 or mat[x][i] == -1) break;
                mat[x][i] = 1;
            }
            for(int i = x + 1; i < m; i++)
            {
                if(mat[i][y] == -2 or mat[i][y] == -1) break;
                mat[i][y] = 1;
            }
            for(int i = x - 1; i >= 0; i--)
            {
                if(mat[i][y] == -2 or mat[i][y] == -1) break;
                mat[i][y] = 1;
            }
        }


        int ans = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(mat[i][j] == 0) ans += 1;

        return ans;
    }
};