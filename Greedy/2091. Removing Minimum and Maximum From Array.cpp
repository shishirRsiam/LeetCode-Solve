class Solution {
public:
    int minimumDeletions(vector<int>& nums) 
    {
        int min_val = INT_MAX, max_val = INT_MIN;
        int n = nums.size(), min_index = 0, max_index = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] < min_val) min_val = nums[i], min_index = i;
            if(max_val < nums[i]) max_val = nums[i], max_index = i;
        }

        int op1 = min_index + 1;
        if(max_index > min_index) op1 += max_index - min_index;

        int op2 = n - max_index; 
        if(max_index > min_index) op2 += max_index - min_index;

        int op3 = (min_index + 1) + (n - max_index); 
        int op4 = (max_index + 1) + (n - min_index); 

        return min({op1, op2, op3, op4});
    }
};