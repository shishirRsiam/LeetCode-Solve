class Solution {
public:
    int minImpossibleOR(vector<int>& nums) 
    {
        int ImpossibleOR = 1;
        unordered_set<int> store(begin(nums), end(nums));
        while(store.count(ImpossibleOR)) ImpossibleOR += ImpossibleOR;
        return ImpossibleOR;
    }
};