class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) 
    {
        int ans = 0;
        unordered_map<string, int> count;
        for(auto &vec : dominoes)
        {
            if(vec[0] > vec[1]) swap(vec[0], vec[1]);
            ans += count[to_string(vec[0]) + to_string(vec[1])]++;
        }
        return ans;    
    }
};