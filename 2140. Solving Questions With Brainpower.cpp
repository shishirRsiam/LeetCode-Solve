class Solution {
public:
    vector<long> memo;
    long backtrack(int index, vector<vector<int>>& questions)
    {
        if(index >= questions.size()) return 0;
        if(memo[index] != -1) return memo[index];

        int points = questions[index][0], brainpower = questions[index][1];
        long skip = backtrack(index + 1, questions);
        long solve = points + backtrack(index + 1 + brainpower, questions);
        return memo[index] = max(skip, solve);
    }
    long long mostPoints(vector<vector<int>>& questions) 
    {
        memo.resize(questions.size(), -1);
        return backtrack(0, questions);
    }
};