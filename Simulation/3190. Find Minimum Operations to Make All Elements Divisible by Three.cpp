class Solution {
public:
    int minimumOperations(vector<int>& nums) 
    {
        int ans = 0;
        for(auto num:nums)
            if(num%3) ans++;
        return ans;
    }
};