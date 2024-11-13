#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T> using pbds = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) 
    {
        long ans = 0;
        sort(begin(nums), end(nums));

        pbds<int>pbds;
        for(auto val:nums)
        {
            int minVal = (lower - val);
            int maxVal = (upper - val);
            auto lowCount = pbds.order_of_key(minVal);
            auto highCount = pbds.order_of_key(maxVal + 1);

            ans += (highCount - lowCount);
            pbds.insert(val);
        }

        return ans;    
    }
};