class Solution {
public:
    int minimumPushes(string word) 
    {
        unordered_map<int, int> count;
        for(auto &ch : word)
            count[ch] += 1;
        
        vector<pair<int, int>> store;
        for(auto &[ch, cnt] : count)
            store.push_back({cnt, ch});
        sort(store.rbegin(), store.rend());

        int ans = 0, pos = 0, cost = 1;
        
        for(auto &[cnt, ch] : store)
        {
            pos += 1;
            ans += (cnt * cost);
            cost += pos % 8 == 0;
        }

        return ans;
    }
};