class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) 
    {
        vector<vector<int>> cost(n, vector<int>(n, INT_MAX));
        for(auto path : prerequisites)
            cost[path[0]][path[1]] = 1;

        for(int k = 0; k < n; k++)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(cost[i][k] == INT_MAX or cost[k][j] == INT_MAX)
                        continue;
                    cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
                }
            }
        }

        vector<bool> ans;
        for(auto que : queries)
            ans.push_back(cost[que[0]][que[1]] != INT_MAX ? true : false);
        return ans;    
    }
};