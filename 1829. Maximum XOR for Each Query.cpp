class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) 
    {
        string bit;
        while(maximumBit--) bit += '1';
        int target = stoi(bit, NULL, 2);
        
        vector<int>ans, prev;
        prev.push_back(0);
        for(auto val:nums) 
            prev.push_back(prev.back() ^ val );

        for(auto val:nums)
        {
            ans.push_back(prev.back() ^ target);
            prev.pop_back();
        }

        return ans;
    }
};