class Solution {
public:
    vector<vector<int>> memo;
    int solve(string cur, int &n)
    {
        int size = cur.size();
        for(int i = 0; i < size - 1; i++)
            if(cur[i] > cur[i + 1]) return false;

        char ch = '0';
        if(size) ch = cur.back();
        if(memo[size][ch] != -1) return memo[size][cur.back()];
        
        if(size == n) return true;
        
        int ans = solve(cur + 'a', n) + solve(cur + 'e', n) +
        solve(cur + 'i', n) + solve(cur + 'o', n) + solve(cur + 'u', n);
        return memo[size][ch] = ans;
    }
    int countVowelStrings(int n) 
    {
        memo.resize(200, vector<int>(200, -1));
        
        return solve("", n);
    }
};