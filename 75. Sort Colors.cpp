class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int zero = 0, one = 0, two = 0;
        for(auto val:nums)
        {
            if(val == 0) zero++;
            else if(val == 1) one++;
            else two++;
        }
        for(auto &val : nums)
        {
            if(zero) val = 0, zero--;
            else if(one) val = 1, one--;
            else val = 2;
        }
    }
};