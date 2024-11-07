class Solution {
public:
    int largestCombination(vector<int>& candidates) 
    {
        unordered_map<int, int>countBits;
        for(auto val:candidates) 
        {
            bitset<32>bits(val);
            
            auto bitStr = bits.to_string();
            for(int i = 0; i < 32; i++)
                countBits[i] += bitStr[i] == '1';
        }   

        int ans = 0;
        for(auto [i, count] : countBits)
            ans = max(ans, count);
        return ans;
    }
};