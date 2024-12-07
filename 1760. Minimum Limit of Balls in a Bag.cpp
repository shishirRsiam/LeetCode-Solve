class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) 
    {
        long ans = INT_MAX, mid;
        long left = 1, right = INT_MAX;    

        // BinarySearchOnAns
        auto canSplit = [&](int mid) 
        {
            int operation = 0;
            for(auto val : nums)
            {
                operation += (val - 1)/ mid;
                if(maxOperations < operation) return false;
            }
            return true;
        };

        while(left <= right)
        {
            mid = left + (right - left) / 2;

            if(canSplit(mid)) ans = mid, right = mid - 1;
            else left = mid + 1;
        }

        return ans;
    }
};