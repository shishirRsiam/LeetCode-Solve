class Solution {
    public:
        vector<vector<int>> sortMatrix(vector<vector<int>>& grid) 
        {
            int n = grid.size();
            unordered_map<int, vector<int>> store;
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    store[i - j].push_back(grid[i][j]);
    
            for(int i = 0; i < n; i++)
            {
                sort(store[i].begin(), store[i].end());
                if(i == 0) continue;
                sort(store[-i].rbegin(), store[-i].rend());
            } 
    
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    grid[i][j] = store[i - j].back();
                    store[i - j].pop_back();
                }
            }
    
            return grid;
        }
    };