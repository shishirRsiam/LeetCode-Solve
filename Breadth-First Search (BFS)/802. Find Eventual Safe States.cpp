class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector<int> inDegree(n);
        vector<vector<int>> reverseGraph(n);
        for(int i = 0; i < n; i++)
        {
            inDegree[i] = graph[i].size();
            for(auto v : graph[i])
                reverseGraph[v].push_back(i);
        }    

        queue<int> que;
        for(int i = 0; i < n; i++)
            if(not inDegree[i]) que.push(i);

        vector<int> ans;
        while(!que.empty())
        {
            auto node = que.front(); que.pop();
            ans.push_back(node);
            for(auto neighbor : reverseGraph[node])
                if(not --inDegree[neighbor]) que.push(neighbor);
        }

        sort(begin(ans), end(ans));
        return ans;
    }
};