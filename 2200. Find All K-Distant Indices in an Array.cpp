class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) 
    {
        vector<int> ans;
        int n = nums.size(), last_index = 0;
        for(int j = 0; j < n; j++)
        {
            if(nums[j] == key) 
            {
                int start = max(last_index, j - k);
                int end = min(j + k + 1, n);
                for(int i = start; i < end; i++)
                    ans.push_back(i);
                last_index = end;
            }
        }
        return ans;
    }
};