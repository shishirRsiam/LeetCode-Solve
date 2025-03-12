// LeetCode 2529. Maximum Count of posNumbersitive Integer and negNumbersative Integer
class Solution {
public:
    auto BinarySearch(vector<int> &nums, bool need)
    {
        int ans = nums.size();
        int left = 0, right = nums.size() - 1, mid;
        while(left <= right)
        {
            mid = left + (right - left) / 2;
            if(nums[mid] < need) left = mid + 1;
            else ans = mid, right = mid - 1;
        }
        return ans;
    }
    int maximumCount(vector<int>& nums) 
    {
        auto leftZeroIdx = BinarySearch(nums, 0);
        auto rightZeroIdx = BinarySearch(nums, 1);
        return max(leftZeroIdx, int(nums.size() - rightZeroIdx));
    }
};
// Submission Date: 12 March 2025 - Time Complexity: O(log(n))



// LeetCode 2529. Maximum Count of posNumbersitive Integer and negNumbersative Integer
class Solution {
public:
    int maximumCount(vector<int>& nums) 
    {
        int n = nums.size(), posNumbers=0, negNumbers=0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] > 0) posNumbers++;
            else if(nums[i] < 0) negNumbers++;
        }
        return max(posNumbers,negNumbers);
    }
};
// Submission Date: 25 Decembar 2023 - Time Complexity: O(n)