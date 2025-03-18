class Solution {
    public:
        int longestNiceSubarray(vector<int>& nums) 
        {
            int ans = 0;
            vector<int> count(40);
            int left = 0, right = 0, n = nums.size();
            while(right < n)
            {
                bitset<32> rightBit(nums[right++]);
                for(int i = 32; i >= 0; i--)
                {
                    count[i] += rightBit[i];
                    while(count[i] > 1)
                    {
                        bitset<32> leftBit(nums[left++]);
                        for(int j = 32; j >= 0; j--)
                            count[j] -= leftBit[j];
                    }
                }
                ans = max(ans, right - left);
            }  
            return ans;  
        }
    };