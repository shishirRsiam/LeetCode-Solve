// Time Complexity: O(n)
// Submitted at Jun 16, 2025 10:22
class Solution {
public:
    int maximumDifference(vector<int>& nums) 
    {
        int ans = 0, maxValue = 0, n = nums.size();   

        vector<int> maxArr(n);
        for(int i = n - 1; i >= 0; i--)
        {
            maxArr[i] = maxValue;
            maxValue = max(maxValue, nums[i]);
        }

        for(int i = 0; i < n; i++)
            ans = max(ans, maxArr[i] - nums[i]);
        return ans ? ans : -1; 
    }
};

// Time Complexity: O(n^2)
// Submitted at Jun 29, 2024 16:31
class Solution {
public:
    int maximumDifference(vector<int>& nums) 
    {
        int ans = INT_MIN, n = nums.size();
        for(int i = 0; i < n; i++)
        {
            for(int j= i + 1; j < n; j++)
            {
                if(nums[i] < nums[j])
                {
                    ans = max(ans, nums[j] - nums[i]);
                }
            }
        }
        return ans == INT_MIN ? -1 : ans;
    }
};