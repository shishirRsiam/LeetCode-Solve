class Solution {
public:
    vector<int> transformArray(vector<int>& nums) 
    {
        vector<int> ans;
        int oddCount = 0;
        for(auto &val : nums)
        {
            if(val % 2) oddCount += 1;
            else ans.push_back(0);
        }
        
        for(int i = 0; i < oddCount; i++) 
            ans.push_back(1);
        return ans;
    }
};