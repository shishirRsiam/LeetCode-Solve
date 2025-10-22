class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) 
    {
        unordered_set<int> seen(begin(nums), end(nums));
        for(int i = 1; i < 110; i++)
            if(not seen.count(i * k)) return i * k;
        return -1; // Not Reched!    
    }
};