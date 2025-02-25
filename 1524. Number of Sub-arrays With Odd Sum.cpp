class Solution {
    public:
        int numOfSubarrays(vector<int>& nums) 
        {
            int even = 1, odd = 0;
            long sum = 0, ans = 0, mod = 1e9 + 7;
            for(auto val : nums)
            {
                sum += val;
                sum % 2 ? odd++ : even++;
                if(sum % 2) ans = (ans + even) % mod;
                else ans += odd;
            }
            return ans % mod;
        }
    };