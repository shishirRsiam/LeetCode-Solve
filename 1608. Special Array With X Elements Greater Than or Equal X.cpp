class Solution {
    public:
        int specialArray(vector<int>& nums) 
        {
            sort(rbegin(nums), rend(nums));
    
            int ans = -1, left = 0, right = 1000, mid;
            auto BinarySearchOnAns = [&](int &mid)
            {
                int count = 0;
                for(auto &val : nums)
                {
                    if(val >= mid) count += 1;
                    else break;
                }
                if(count == mid) ans = count;
                return count >= mid;
            };
    
            while(left <= right)
            {
                mid = left + (right - left) / 2;
                if(BinarySearchOnAns(mid)) left = mid + 1;
                else right = mid - 1;
            }
    
            return ans;
        }
    };