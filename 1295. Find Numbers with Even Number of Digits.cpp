class Solution {
public:
    int findNumbers(vector<int>& nums) 
    {
        int ans = 0;
        for(auto &val : nums)
            ans += to_string(val).size() % 2 == 0;
        return ans;
    }
};