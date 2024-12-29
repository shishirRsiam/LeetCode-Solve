class Solution {
public:
    int mod = 1e9 + 7, k;
    vector<vector<int>> memo;
    unordered_map<int, unordered_map<char, int>> count;
    long solve(int target_idx, int cur_idx, string &target)
    {
        if(target_idx == target.size()) return 1;
        if(cur_idx == k) return 0;

        if(memo[target_idx][cur_idx] != -1) return memo[target_idx][cur_idx];

        long take = solve(target_idx + 1, cur_idx + 1, target) * count[cur_idx][target[target_idx]];
        long not_take = solve(target_idx, cur_idx + 1, target);
        return memo[target_idx][cur_idx] = (take + not_take) % mod;
    }
    int numWays(vector<string>& words, string target) 
    {
        memo.resize(1005, vector<int>(1005, -1));
        k = words[0].size();
        for(auto s : words)
            for(int i = 0; i < k; i++) count[i][s[i]]++;

        return solve(0, 0, target);
    }
};