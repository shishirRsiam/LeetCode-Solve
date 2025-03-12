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