class Solution {
    public:
        int maximumCandies(vector<int>& candies, long long k) 
        {
            auto BinarySearchOnAns = [&](int &mid)
            {
                long count = 0;
                for(auto &val : candies)
                {
                    count += val / mid;
                    if(count >= k) return true;
                }
                return false;
            };
    
            int ans = 0, left = 1, right = 1e7, mid;
            while(left <= right)
            {
                mid = left + (right - left) / 2;
                if(BinarySearchOnAns(mid)) ans = mid, left = mid + 1;
                else right = mid - 1;
            }
            return ans;
        }
    };