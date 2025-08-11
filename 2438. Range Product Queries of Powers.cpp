class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) 
    {
        vector<int> store_power, ans;
        long sum = 0, max_power = 17179869184;
        while(max_power)
        {
            if(max_power + sum <= n) 
            {
                sum += max_power;
                store_power.push_back(max_power);
            }
            max_power /= 2;
        }
        reverse(begin(store_power), end(store_power));

        long mod = 1e9 + 7, mul, l, r;
        for(auto querie : queries)
        {
            mul = 1, l = querie[0], r = querie[1];
            for(int i = l; i <= r; i++)
                mul = (mul *  store_power[i]) % mod;
            ans.push_back(mul);
        }
        return ans;
    }
};