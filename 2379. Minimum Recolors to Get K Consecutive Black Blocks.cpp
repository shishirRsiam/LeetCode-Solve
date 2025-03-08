class Solution {
    public:
        int minimumRecolors(string blocks, int k) 
        {
            int cnt = 0, ans = INT_MAX;
            int i = 0, j = 0, n = blocks.size();
            while(j < n)
            {
                if(blocks[j++] == 'W') cnt++;
                while(j - i > k)
                    if(blocks[i++] == 'W') cnt--;
                if(j - i == k) ans = min(ans, cnt);
            }
            return ans;
        }
    };