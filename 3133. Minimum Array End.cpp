class Solution {
public:
    long long minEnd(int n, int x) 
    {
        long ans = x;
        for(int _ = 1; _ < n; _++)
            ans = ((ans + 1) | x);
        return ans;
    }
};