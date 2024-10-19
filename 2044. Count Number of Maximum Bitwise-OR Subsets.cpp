class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) 
    {
        unordered_map<int, int> count;
        int n = nums.size(), size = (1 << n), maxOr = 0;;
        for(int i = 0; i < size; i++)
        {
            int Or = 0;
            for(int j = 0; j < n; j++)
                if(i & (1 << j)) Or |= nums[j];
                
            count[Or] += 1;
            maxOr = max(maxOr, Or);
        }
        return count[maxOr];
    }
};