class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        unordered_set<int> row, col;
        int n = matrix.size(), m = matrix[0].size();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(not matrix[i][j])
                {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }    

        for(auto &i : row)
        {
            for(int j = 0; j < m; j++)
            {
                matrix[i][j] = 0;
            }
        }
        for(auto &j : col)
        {
            for(int i = 0; i < n; i++)
            {
                matrix[i][j] = 0;
            }
        }
    }
};