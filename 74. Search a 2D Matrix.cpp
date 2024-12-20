class Solution {
public:
    bool BinarySearch(vector<int> &nums, int &target)
    {
        int i = 0, j = nums.size() - 1;
        while(i <= j)
        {
            int mid = (j + i) / 2;
            if(nums[mid] == target) return true;
            else if(nums[mid] < target) i = mid + 1;
            else j = mid - 1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int i = 0, j = matrix.size() - 1;
        while(i <= j)
        {
            int mid = (j + i) / 2;
            auto nums = matrix[mid];
            if(nums[0] <= target)
            {
                if(BinarySearch(nums, target)) return true;
                i = mid + 1;
            }
            else j =  mid - 1;
        }
        return false;
    }
};