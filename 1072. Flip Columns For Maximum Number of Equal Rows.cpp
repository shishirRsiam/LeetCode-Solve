class Solution {
public:
    auto flipRow(vector<int> vec)
    {
        for(auto &val : vec)
            val = (val ? 0 : 1);
        return vec;
    }
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) 
    {
        int ans = 0;
        map<vector<int>, int>store;
        for(auto mat : matrix)
            store[mat] += 1;
        
        for(auto mat : matrix)
        {
            ans = max(ans, store[mat]);
            auto vec = flipRow(mat);
            ans = max(ans, store[mat] + store[vec]);
        }

        return ans;
    }
};