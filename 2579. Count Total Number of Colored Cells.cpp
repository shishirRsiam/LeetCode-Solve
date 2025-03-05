class Solution {
    public:
        long long coloredCells(int n) 
        {
            long ans = 1, color = 4;
            for(int i = 1; i < n; i++)
                ans += color, color += 4;
            return ans;    
        }
    };