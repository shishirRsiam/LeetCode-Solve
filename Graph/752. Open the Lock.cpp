class Solution {
public:
    unordered_map<string,bool>visited;
    int BFS(string source, string target)
    {
        int ans = 0;
        queue<string>q; 
        if(!visited[source]) q.push(source);
        while(!q.empty())
        {
            int n = q.size();
            while(n--)
            {
                string par = q.front(); q.pop();
                if(par == target) return ans;
                for(int i=0;i<4;i++)
                {
                    string tmp = par, tmp2 = par;
                    tmp[i] += 1, tmp2[i] -= 1;
                    if(tmp[i]==':') tmp[i] = '0';
                    if(tmp2[i] == '/') tmp2[i] = '9';
                    if(!visited[tmp]) visited[tmp] = true, q.push(tmp);
                    if(!visited[tmp2]) visited[tmp2] = true, q.push(tmp2);
                }
            }
            ans++;
        }
        return -1;
    }
    int openLock(vector<string>& deadends, string target) 
    {
        for(auto s:deadends) visited[s] = true;
        return BFS("0000", target);
    }
};