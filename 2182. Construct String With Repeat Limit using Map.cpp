class Solution {
public:
    void eraseData(map<char, int> &store, char ch)
    {
        if(not store[ch])
            store.erase(ch);
    }
    string repeatLimitedString(string s, int repeatLimit) 
    {
        map<char, int> store;
        for(auto ch : s)
            store[ch] += 1;
        
        string ans;
        int count = 0;

        char prev = '-';
        while(!store.empty())
        {
            char ch = store.rbegin()->first;

            if(prev != ch or count < repeatLimit)
            {
                ans += ch;
                store[ch] -= 1;
                eraseData(store, ch);

                if(prev == ch) count += 1;
                else count = 1, prev = ch;
            }
            else 
            {
                bool flag = true;
                for(char nextChar = ch - 1; nextChar >= 'a'; nextChar--)
                {
                    if(store.count(nextChar))
                    {
                        ans += nextChar;
                        store[nextChar] -= 1;
                        eraseData(store, nextChar);
                        count = 1, prev = nextChar, flag = false;
                        break;
                    }
                }
                if(flag) break;
            }
        }

        return ans;    
    }
};