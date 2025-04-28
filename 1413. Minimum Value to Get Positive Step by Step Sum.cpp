class Solution {
public:
    int minStartValue(vector<int>& nums) 
    {
        int sum = 0, minSum = (100 * 100);
        for(auto &val : nums)
        {
            sum += val;
            minSum = min(minSum, sum);
        }
        return abs(min(minSum, 0) - 1);
    }
};