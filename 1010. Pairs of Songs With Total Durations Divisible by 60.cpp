class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) 
    {
        vector<int> count(65);
        int ans = 0, n = time.size(), mod;
        for(int i = 0; i < n; i++)
        {
            mod = time[i] % 60;
            ans += count[60 - mod];
            count[mod]++;
        }
        return ans + ((count[0] * long(count[0] - 1)) / 2);
    }
};


class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) 
    {
        vector<int> count(65);
        int ans = 0, n = time.size(), mod;
        for(int i = 0; i < n; i++)
        {
            mod = time[i] % 60;
            if(mod == 0) ans += count[mod];
            else ans += count[60 - mod];
            // ans += count[(mod == 0 ? 0 : 60) - mod];
            count[mod]++;
        }
        return ans;
    }
};