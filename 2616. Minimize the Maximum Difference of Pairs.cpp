class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) 
    {
        int n = nums.size();
        sort(begin(nums), end(nums));
        auto BinarySearchOnAns = [&](int mid)
        {
            int pairs = 0, i = 0;
            for(int i = 0; i < n - 1 and pairs <= p; i++)
            {
                if(nums[i + 1] - nums[i] <= mid)
                {
                    pairs += 1;
                    i += 1;
                }
            }
            return pairs >= p;
        };

        int left = 0, right = 1e9 + 7, ans = -1, mid;
        while(left <= right)
        {
            mid = left + (right - left) / 2;
            if(BinarySearchOnAns(mid)) ans = mid, right = mid - 1;
            else left = mid + 1;
        }
        return ans;
    }
};