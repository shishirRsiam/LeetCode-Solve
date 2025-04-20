class Solution {
public:
    int numRabbits(vector<int>& answers) 
    {
        int ans = 0;
        unordered_map<int, int> count;
        for(auto &val : answers)
        {
            if(count[val] > val) count[val] = 0;
            if(not count[val]) ans += val + 1;
            count[val] += 1;
        }
        return ans;
    }
};