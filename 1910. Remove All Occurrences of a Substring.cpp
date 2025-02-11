class Solution {
    public:
        string removeOccurrences(string s, string part) 
        {
            string store;
            int n = s.size(), m = part.size();
            for(int i = 0; i < n; i++)
            {
                store += s[i];
                if(store.size() < m) continue;
                string temp = store.substr(store.size() - m);
                if(temp == part) store.erase(store.begin() + store.size() - m, store.end());
            }
            return store;
        }
    };