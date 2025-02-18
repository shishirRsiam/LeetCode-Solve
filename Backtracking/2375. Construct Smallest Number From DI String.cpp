class Solution {
    public:
        int ans = INT_MAX;
        void backtrack(int idx, string cur, string &pattern, vector<bool> &used)
        {
            if(idx == pattern.size())
            {
                ans = min(ans, stoi(cur));
                return;
            }
            for(int i = 1; i <= 9; i++)
            {
                if(used[i]) continue;
                
                used[i] = true;
                if(pattern[idx] == 'I' and cur.back() - '0' < i)
                    backtrack(idx + 1, cur + to_string(i), pattern, used);
                else if(pattern[idx] == 'D' and cur.back() - '0' > i)
                    backtrack(idx + 1, cur + to_string(i), pattern, used);
                used[i] = false;
            }
        }
        string smallestNumber(string pattern) 
        {
            vector<bool> used(10);
            int n = pattern.size();
            for(int i = 1; i <= 9; i++)
            {
                used[i] = true;
                backtrack(0, to_string(i), pattern, used);
                used[i] = false;
            }
            return to_string(ans);
        }
    };