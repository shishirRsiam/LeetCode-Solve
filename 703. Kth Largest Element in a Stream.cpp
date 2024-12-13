#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;


template <typename T> using pbds = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

class KthLargest {
public:
    int target;
    pbds<int>pbds;
    KthLargest(int k, vector<int>& nums) 
    {
        for(auto &val : nums) pbds.insert(val);
        target = k - 1;
    }
    
    int add(int val) 
    {
        pbds.insert(val);
        auto res = pbds.find_by_order(pbds.size() - target - 1);
        return *res;
    }
};