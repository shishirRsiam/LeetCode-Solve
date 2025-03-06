class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) 
        {
            map<int,int>mp;
            int n = grid.size();
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                    mp[grid[i][j]]++;
            }
    
            int rep, miss = 0;
            n = n*n;
            for(int i=1;i<=n;i++)
            {
                if(mp[i]==2) rep = i;
                else if(mp[i]==0) miss = i;
            }
            return {rep,miss};
        }
    };