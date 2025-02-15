class Solution {
    public:
        bool flag = false;
        void backtrack(string &s, int cur, int n, int cur_sum, int need_sum)
        {
            if(cur_sum == need_sum and cur == n) flag = true;
            if(flag or cur == n) return;
    
            string cur_s;
            for(int i = cur; i < n; i++)
            {
                cur_s += s[i];
                backtrack(s, i + 1, n, cur_sum + stoi(cur_s), need_sum);
            }
        }
        int punishmentNumber(int n) 
        {
            int ans = 0;
            for(int i = 1; i <= n; i++)
            {
                flag = false;
                string s = to_string(i * i);
                backtrack(s, 0, s.size(), 0, i);
                ans += i * i * flag;
            }
            return ans;    
        }
    };