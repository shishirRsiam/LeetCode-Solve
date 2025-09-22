class Solution {
public:
    int maxFrequencyElements(vector<int> &nums)
    {
        vector<int> freq(105);
        int n = nums.size(), mx = 0;
        for(int i = 0; i < n; i++)
        {
            freq[nums[i]]++;
            mx = max(mx, freq[nums[i]]);
        }

        int ans = 0;
        for(auto x : freq)
            if(x == mx) ans += x;
        return ans;
    }
};