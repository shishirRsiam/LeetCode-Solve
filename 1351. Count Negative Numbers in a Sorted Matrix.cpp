class Solution {
public:
    int countNegatives(vector<vector<int>>& g) 
    {
        int ans=0;
        for(int i=0;i<g.size();i++)
        {
            for(int j=0;j<g[i].size();j++)
            {
                if(g[i][j] < 0)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};