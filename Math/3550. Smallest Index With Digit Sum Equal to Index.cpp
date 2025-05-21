class Solution {
public:
    int smallestIndex(vector<int>& nums) 
    {
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            int sum = 0;
            auto s = to_string(nums[i]);
            for(auto &ch : s)
                sum += ch - '0';
            if(sum == i) return i;
        }    
        return -1;
    }
};