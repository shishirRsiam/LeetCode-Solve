class Solution {
public:
    int numberOfBeams(vector<string>& bank) 
    {
        vector<int> store;
        for(auto &s : bank)
        {
            auto cnt = count(s.begin(), s.end(), '1');
            if(cnt) store.push_back(cnt);
        }

        int ans = 0, l = store.size();
        for(int i = 1; i < l; i++)
            ans += (store[i] * store[i - 1]);
        return ans;
    }
};