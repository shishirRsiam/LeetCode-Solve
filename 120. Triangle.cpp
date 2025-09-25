class Solution {
public:
    int n;
    vector<vector<int>> cache;
    int solve(int row, int col, vector<vector<int>>& triangle) 
    {
        if (row == n - 1) 
            return triangle[row][col];

        if (cache[row][col] != INT_MAX) 
            return cache[row][col];

        int down = triangle[row][col] + solve(row + 1, col, triangle);
        int diagonal = triangle[row][col] + solve(row + 1, col + 1, triangle);

        return cache[row][col] = min(down, diagonal);
    }

    int minimumTotal(vector<vector<int>>& triangle) 
    {
        n = triangle.size();
        cache.assign(n, vector<int>(n, INT_MAX));
        return solve(0, 0, triangle);
    }
};
