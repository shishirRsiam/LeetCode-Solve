class Solution {
public:
    int averageValue(vector<int>& nums) 
    {
        int count = 0, sum = 0;
        for(auto &val : nums)
            if(not(val % 2) and not(val % 3)) 
                sum += val, count += 1;
        return count ? sum / count : count;
    }
};