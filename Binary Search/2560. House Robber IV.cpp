class Solution {
    public:
        int minCapability(vector<int>& nums, int k) 
        {
            int n = nums.size();
            auto canRob = [&](int &mid)
            {
                int count = 0;
                for(int i = 0; i < n; i++)
                {
                    if(nums[i] <= mid) count += 1, i += 1;
                    if(count == k) return true;
                }
                return false;
            };
    
    
            int left = 1, right = 1e9, mid;
            while(left <= right)
            {
                mid = left + (right - left) / 2;
                if(canRob(mid)) right = mid - 1;
                else left = mid + 1;
            }
            return left;
        }
    };