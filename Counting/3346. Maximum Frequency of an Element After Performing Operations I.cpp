// LeetCode
// 3346. Maximum Frequency of an Element After Performing Operations I
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) 
    {
        int MAX = 1e5 + 5;
        vector<int> diffArr(MAX + 3), count(MAX + 3);
        for(auto &val : nums)
        {
            int min_range = max(0, val - k);
            int max_range = min(MAX, val + k);

            count[val] += 1;
            diffArr[min_range] += 1;
            diffArr[max_range + 1] -= 1;
        }

        int ans = 0;
        for(int i = 0; i < MAX; i++)
        {
            if(i) diffArr[i] += diffArr[i - 1]; 
            ans = max(ans, min(diffArr[i], count[i] + numOperations));
        }
        return ans;
    }
};