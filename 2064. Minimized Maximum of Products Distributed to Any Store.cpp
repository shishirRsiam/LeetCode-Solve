class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) 
    {
        int left = 1, right = *max_element(begin(quantities), end(quantities));
        int ans = right, mid;

        auto BinarySearchOnAns = [&](int mid)
        {
            int count = 0;
            for(auto quantitie : quantities)
                count += ceil(quantitie / double(mid));
            return count <= n;
        };

        while(left <= right)
        {
            mid = (left + right) / 2;
            if(BinarySearchOnAns(mid)) 
            {
                ans = mid;
                right = mid - 1;
            }
            else left = mid + 1;
        }

        return ans;
    }
};