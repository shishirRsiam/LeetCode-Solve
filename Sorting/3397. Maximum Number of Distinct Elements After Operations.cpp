class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) 
    {
        int ans = 0, n = nums.size();
        sort(begin(nums), end(nums));

        int prevNumber = nums[0] - k;
        for(int i = 0; i < n; i++)
        {
            if(i and nums[i] != nums[i - 1] and !(nums[i] - k <= prevNumber)) 
                prevNumber = nums[i] - k;

            int curNumber = min(nums[i] + k, max(prevNumber, nums[i] - k));
            ans += curNumber == prevNumber;
            if(prevNumber <= nums[i] + k) prevNumber += 1;
        }
        return ans;
    }
};