class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) 
    {
        vector<pair<int, int>> store(1e5+5);
        int n = mat.size(), m = mat[0].size(), size = arr.size();
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                store[mat[i][j]] = {i, j};

        vector<int> countRow(1e5 + 5), countCol(1e5+5);
        for(int k = 0; k < size; k++)
        {
            auto [i, j] = store[arr[k]];
            countRow[i] += 1, countCol[j] += 1;
            if(countRow[i] == m or countCol[j] == n) return k;
        }
        return 0;
    }
};