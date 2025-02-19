class Solution {
    public:
        string s = "abc", ans;
        void backtrack(string cur, int &n, int &k, int &count)
        {
            if(count == k) return;
            if(cur.size() == n)
            {
                ans = cur, count += 1;
                return;
            }
            for(auto ch : s)
            {
                if(cur.size() and ch == cur.back()) continue;
                backtrack(cur + ch, n, k, count);
            }
        }
        string getHappyString(int n, int k) 
        {
            int count = 0;
            backtrack("", n, k, count);
            return count == k ? ans : "";
        }
    };