class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) 
    {
        int ans = 0, max_i = values[0], n = values.size();
        for(int j = 1; j < n; j++)
        {
            ans = max(ans, max_i + values[j] - j);
            max_i = max(max_i, values[j] + j);
        }
        return ans;
    }
};