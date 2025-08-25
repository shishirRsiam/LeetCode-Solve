class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) 
    {
        map<int, vector<int>> mp;
        int n = mat.size(), m = mat[0].size();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int idx = i + j;
                if(idx % 2) mp[idx].push_back(mat[i][j]);
                else mp[idx].insert(mp[idx].begin(),mat[i][j]);
            }
        }

        vector<int> ans;
        for(auto x : mp)
            for(int v:x.second) ans.push_back(v);
        
        return ans;
    }
};