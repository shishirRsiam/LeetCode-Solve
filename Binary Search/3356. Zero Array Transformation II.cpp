// LeetCode 13 Mar 2025 PODT: 3356. Zero Array Transformation II
class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) 
    {
        int n = nums.size();
        auto BinarySearchOnAns = [&](int &mid)
        {
            vector<int> diffArray(n + 1);
            for(int i = 0; i < mid; i++)
            {
                int l = queries[i][0], r = queries[i][1], val = queries[i][2];
                diffArray[l] -= val, diffArray[r + 1] += val;
            }
            for(int i = 0; i < n; i++)
            {
                if(i) diffArray[i] += diffArray[i - 1];
                if(diffArray[i] + nums[i] > 0) return false;
            }
            return true;
        };
        
        int ans = -1, left = 0, right = queries.size(), mid;
        while(left <= right)
        {
            mid = left + (right - left) / 2;
            if(BinarySearchOnAns(mid)) ans = mid, right = mid - 1;
            else left = mid + 1;
        }
        return ans;
    }
};