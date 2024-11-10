class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int target) 
    {
        long Or = 0;
        vector<int>bits(32);
        int ans = INT_MAX, left = 0, right = 0, n = nums.size();
        while(right < n)
        {
            Or |= nums[right];
            bitset<32>Bit(nums[right++]);
            for(int i = 0; i < 32; i++)
                bits[i] += Bit[i];

            while(left < right and Or >= target)
            {
                ans = min(ans, right - left);

                string num;
                bitset<32>Bit(nums[left++]);
                for(int i = 31; i >= 0; i--)
                {
                    bits[i] -= Bit[i];
                    num += bits[i] ? '1' : '0';
                }
                Or = stoi(num, NULL, 2);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};




class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int target) 
    {
        long Or = 0;
        vector<int>bits(32);
        int ans = INT_MAX, left = 0, right = 0, n = nums.size();
        while(right < n)
        {
            Or |= nums[right];
            bitset<32>Bit(nums[right++]);
            for(int i = 0; i < 32; i++)
                bits[i] += Bit[i];

            while(left < right and Or >= target)
            {
                ans = min(ans, right - left);

                bitset<32>Bit(nums[left++]);
                for(int i = 0; i < 32; i++)
                    bits[i] -= Bit[i];
                
                Or = 0;
                for(int i = 0; i < 32; i++)
                    if(bits[i]) Or |= (1 << i);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};