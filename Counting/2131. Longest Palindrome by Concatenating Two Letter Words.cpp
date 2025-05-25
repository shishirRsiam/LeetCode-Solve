class Solution {
public:
    int longestPalindrome(vector<string>& words) 
    {
        unordered_map<string, int> count;
        unordered_set<string> visited, store;
        for(auto &s : words) 
        {
            count[s] += 1;
            store.insert(s);
        }
        
        int ans = 0, flag = true;
        for(auto &s : store)
        {
            int cnt = count[s];
            if(visited.count(s)) continue;
            if(s[0] == s[1]) 
            {
                if(cnt % 2)
                {
                    cnt -= 1;
                    if(flag)
                    {
                        ans += 2;
                        flag = false;
                    }
                }
                ans += cnt * 2;
                continue;
            }

            string ss = string{ s[1], s[0] };
            
            int cnt2 = count[ss];
            int maxAdd = min(cnt, cnt2);
            ans += (maxAdd * 2) * 2;

            visited.insert(s);
            visited.insert(ss);
        }
        return ans;
    }
};