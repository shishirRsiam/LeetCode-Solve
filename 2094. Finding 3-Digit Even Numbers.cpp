class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& s) 
    {
        int n = s.size();
        unordered_set<string> store;
        for(int i = 0; i < n; i++)
        {
            auto ch1 = s[i] + '0';
            for(int j = 0; j < n; j++)
            {
                if(i == j) continue;
                auto ch2 = s[j] + '0';
                for(int k = 0; k < n; k++)
                {
                    if(i == k or j == k or s[k] % 2) continue;

                    auto ch3 = s[k] + '0';
                    string ok = "000";
                    ok[0] = ch1, ok[1] = ch2, ok[2] = ch3;
                    store.insert(ok);
                }
            }
        }   

        vector<int> ans;
        for(auto w : store)
        {
            if(w[0] == '0' or w[2] % 2) continue;
            ans.push_back(stoi(w));
        }
        sort(begin(ans), end(ans));
        return ans;
    }
};