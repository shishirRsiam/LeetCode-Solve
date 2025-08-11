class Solution {
public:
    vector<int> countBit;
    long getOr()
    {
        string bit;
        for(int i = 32; i >= 0; i--)
            bit += countBit[i] ? '1' : '0';
        return stoll(bit, NULL, 2);
    }
    void addedToCountBit(int num)
    {
        bitset<33>bit(num);
        for(int i = 0; i < 33; i++)
            countBit[i] += bit[i];
    }
    void removeCountBit(int num)
    {
        bitset<33>bit(num);
        for(int i = 0; i < 33; i++)
            countBit[i] -= bit[i];
    }
    vector<int> smallestSubarrays(vector<int>& nums) 
    {
        int n = nums.size();
        countBit.resize(40, 0);
        
        vector<int> suffixOR(n);
        suffixOR[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) 
            suffixOR[i] = suffixOR[i + 1] | nums[i];
        
        int i = 0, j = 0;
        vector<int> ans(n);
        while (j < n) 
        {
            addedToCountBit(nums[j++]);
            while (i < j and getOr() == suffixOR[i]) 
            {
                ans[i] = j - i;
                removeCountBit(nums[i++]);
            }
        }
        return ans;    
    }
};