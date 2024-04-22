class Solution {
public:

    bool visited[100005];
    vector<int> edg[100005];
    void dfs(int source, int &ans)
    {
        ans++;
        visited[source] = true;
        for(int child:edg[source])
            if(!visited[child]) dfs(child, ans);
    }

    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) 
    {
        for(int val:restricted) visited[val] = true;
        for(auto x:edges)
        {
            edg[x[0]].push_back(x[1]);
            edg[x[1]].push_back(x[0]);
        }
        
        int ans = 0;
        dfs(0, ans);
        return ans;
    }
};