class Solution {
public:
    void rotate(vector<vector<int>>& mat) 
    {
        vector<vector<int>>tmp;
        int n = mat.size();
        for(int i=0;i<n;i++)
        {
            vector<int>t;
            for(int j=n-1;j>=0;j--)
            {
                t.push_back(mat[j][i]);
            }
            tmp.push_back(t);
        }
        mat=tmp;
    }
};