class Solution {
    public:
        int countPairs(vector<int>& deliciousness) 
        {
            long ans = 0, mod = 1e9 + 7; 
            unordered_map<int, int> count;
            for(auto &val : deliciousness)
            {
                int curPow = 1;
                while(curPow + curPow < 1e7)
                {
                    ans += (count[(curPow - val)]);
                    curPow += curPow;
                }
                ans %= mod;
                count[val] += 1;
            }  
            return ans;
        }
    };