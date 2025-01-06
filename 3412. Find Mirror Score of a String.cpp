class Solution {
public:
    long long calculateScore(string s) 
    {
        long ans = 0, n = s.size();
        unordered_map<char, stack<int>> store;
        for(int i = 0; i < n; i++)
        {
            auto ch = s[i];
            char mirror_ch = 25 - (ch - 'a') + 'a';
            // cout<<"ch:"<<ch<<" - mirror_ch:"<<mirror_ch<<endl;
            if(store[mirror_ch].size()) 
            {
                ans += i - store[mirror_ch].top();
                store[mirror_ch].pop();
                continue;
            }
            store[ch].push(i);
        }
        return ans;
    }
};