class Solution {
public:
    int n;
    vector<vector<int>> fruits_copy, memo;
    auto child1Collection()
    {
        int count = 0;
        for(int i = 0; i < n; i++)
            count += fruits_copy[i][i];
        return count;
    }
    auto child2Collection(int i, int j)
    {
        if (i < 0 or i >= n or j < 0 or j >= n or i == j or i > j) 
            return 0;

        if(memo[i][j] != -1)
            return memo[i][j];
        
        auto op1 = child2Collection(i + 1, j - 1);
        auto op2 = child2Collection(i + 1, j);
        auto op3 = child2Collection(i + 1, j + 1);
        return memo[i][j] = fruits_copy[i][j] + max({op1, op2, op3});
    }
    auto child3Collection(int i, int j)
    {
        if (i < 0 or i >= n or j < 0 or j >= n or i == j or j > i) 
            return 0;

        if(memo[i][j] != -1)
            return memo[i][j];
        
        auto op1 = child3Collection(i - 1, j + 1);
        auto op2 = child3Collection(i, j + 1);
        auto op3 = child3Collection(i + 1, j + 1);
        return memo[i][j] = fruits_copy[i][j] + max({op1, op2, op3});
    }
    int maxCollectedFruits(vector<vector<int>>& fruits) 
    {
        n = fruits.size();
        fruits_copy = fruits;
        memo.resize(n, vector<int>(n, -1));

        int child1 = child1Collection();
        int child2 = child2Collection(0, n - 1);
        int child3 = child3Collection(n - 1, 0);

        return child1 + child2 + child3;
    }
};