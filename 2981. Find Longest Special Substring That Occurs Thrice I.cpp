class Solution {
public:
    int maximumLength(string s) 
    {
        int n = s.size();
        unordered_map<string, int> store;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                string temp;
                for(int k = i; k <= j; k++)
                    temp += s[k];
                store[temp] += 1;
            }
        }

        string ans;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                string temp;
                for(int k = i; k <= j; k++)
                    temp += s[k];
                
                set<char>ch(begin(temp), end(temp));
                if(ch.size() == 1 and store[temp] > 2)
                {
                    if(temp.size() > ans.size())
                    {
                        ans = temp;
                    }
                }
            }
        }

        return ans.size() ? ans.size() : -1;
    }
};