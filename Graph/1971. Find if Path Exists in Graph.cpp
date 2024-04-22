class Solution {
public:
    bool visited[200005];
    vector<int> ed[200005];
    void dfs(int source)
    {
        visited[source] = true;
        for(int child:ed[source])
            if(!visited[child]) dfs(child);
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        for(auto v:edges)
        {
            ed[v[0]].push_back(v[1]);
            ed[v[1]].push_back(v[0]);
        }
        dfs(source);
        return visited[destination];
    }
};