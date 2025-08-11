class Solution {
public:
    int movementCost(int l, int r, int start) 
    {
        if (start <= l) return r - start;
        if (r <= start) return start - l;
        return min(2 * (start - l) + (r - start), 2 * (r - start) + (start - l));
    }
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) 
    {
        int n = fruits.size();
        vector<int> prefix(n + 1);

        for (int i = 0; i < n; ++i) 
            prefix[i + 1] = prefix[i] + fruits[i][1];

        int ans = 0, l = 0, r = 0;
        while(r < n)
        {
            while (l <= r and movementCost(fruits[l][0], fruits[r][0], startPos) > k) 
                l++;

            if (l <= r)
                ans = max(ans, prefix[r + 1] - prefix[l]);
            r++;
        }
        return ans;
    }
};