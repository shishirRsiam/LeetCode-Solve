class Solution {
public:
    int maximumXOR(vector<int>& nums) 
    {
        int ans = 0;
        vector<bool> added(32);
        for(auto &val : nums) 
        {
            bitset<32> bit(val), newbit(0);
            for(int i = 0; i < 32; i++)
            {
                if(bit[i] and not added[i])
                {
                    newbit[i] = 1;
                    added[i] = true;
                }
            }
            ans = ans xor newbit.to_ulong();
        }
        return ans;    
    }
};