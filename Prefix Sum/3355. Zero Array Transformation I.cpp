class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) 
    {
        int n = nums.size();
        vector<int> difArray(n + 1);
        for(auto &que : queries)
        {
            difArray[que[0]] += 1;
            difArray[que[1] + 1] -= 1;
        }

        for(int i = 1; i < n; i++)
            difArray[i] += difArray[i - 1];
        
        for(int i = 0; i < n; i++)
            if(nums[i] > difArray[i]) return false;
            
        return true;    
    }
};