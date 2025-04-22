class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) 
    {
        long sum = 0;
        vector<bool> ans;
        for(auto &val : nums)
        {
            sum += sum + val;
            ans.push_back(sum % 5 == 0);
            sum %= 5;
        }
        return ans;
    }
};