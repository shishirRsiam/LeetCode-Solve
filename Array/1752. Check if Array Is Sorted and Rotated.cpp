class Solution {
public:
    bool check(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>t(nums.begin(),nums.end());
        sort(t.begin(),t.end());
        for(int i=0;i<n;i++)
        {
            nums.push_back(nums[0]);
            nums.erase(nums.begin());
            if(nums == t) return true;
        }
        return false;
    }
};