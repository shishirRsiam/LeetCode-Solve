class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) 
    {
        long long ans = 0;
        int minpos = -1, maxpos = -1, unbound = -1, n = nums.size();
        for(int i = 0; i < n; i++)
        {
            if(nums[i] < minK or nums[i] > maxK) unbound = i;
            if(nums[i]==minK) minpos = i;
            if(nums[i]==maxK) maxpos = i;

            int canadd = min(minpos, maxpos) - unbound;
            if(canadd > 0) ans += canadd;
        }
        return ans;
    }
};