class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) 
    {
        int n = board.size(), val = 1;
        
        bool flag = true;
        vector<pair<int, int>> store_index(n * n + 1);
        for(int i = n - 1; i >= 0; i--)
        {
            if(flag)
                for(int j = 0; j < n; j++)
                    store_index[val++] = {i, j};
            else 
                for(int j = n - 1; j >= 0; j--)
                    store_index[val++] = {i, j};
            flag = not flag;
        }

        queue<pair<int, int>> que;
        que.push({1, 0});

        vector<bool> visited(n * n + 1);
        visited[1] = true;

        while(not que.empty())
        {
            auto [cur_destination, steps] = que.front(); que.pop();

            if(cur_destination == n * n) return steps;
            for(int _ = 0; _ < 6; _++)
            {
                cur_destination += 1;
                if(cur_destination > n * n) continue;
                if(not visited[cur_destination])
                {
                    visited[cur_destination] = true;
                    auto [i, j] = store_index[cur_destination];

                    int next_destination = (board[i][j] == -1) ? cur_destination : board[i][j];
                    que.push({next_destination, steps + 1});
                }
            }
        }

        return -1;
    }
};