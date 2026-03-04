class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) 
    {
        int n = mat.size(), m = mat[0].size(), ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==1)
                {
                    int cnt = 0;
                    for(int k=0;k<m;k++)
                        if(mat[i][k]==1) cnt++;
                    for(int k=0;k<n;k++)
                        if(mat[k][j]==1) cnt++;
                    if(cnt==2) ans++;
                }
            }
        }
        return ans;
    }
};