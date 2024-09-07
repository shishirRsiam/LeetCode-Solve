class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) 
    {
        int ans = 0, x = 0, y = 0;
        pair<int, int> dir = {0, 1};
        set<vector<int>>st(begin(obstacles), end(obstacles));
        for(auto com:commands)
        {
            if(com == -1) dir = {dir.second, -dir.first};
            else if(com == -2) dir = {-dir.second, dir.first};
            else
            {
                for(int i = 0; i < com; i++)
                {
                    int newX = x + dir.first;
                    int newY = y + dir.second;
                    if(st.count({newX, newY})) break;
                    x = newX, y = newY;
                }
            }
            ans = max(ans, (x*x + y*y));
        }
        return ans;
    }
};