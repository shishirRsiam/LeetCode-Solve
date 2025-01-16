class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) 
    {
        int Xor1 = 0, Xor2 = 0;
        for(auto &val : nums1) Xor1 = Xor1 xor val;
        for(auto &val : nums2) Xor2 = Xor2 xor val;
        
        int ans = 0;
        if(nums2.size() % 2) ans ^= Xor1;
        if(nums1.size() % 2) ans ^= Xor2;
        return ans;
    }
};