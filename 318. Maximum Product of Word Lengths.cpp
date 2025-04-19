class Solution {
public:
    int maxProduct(vector<string>& words) 
    {
        int n = words.size();
        vector<unordered_map<int, int>> store(n);
        for(int i = 0; i < n; i++)
        {
            for(auto ch : words[i])
            {
                store[i][ch - 'a'] += 1;
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                bool isCommotWord = false;
                int mul = words[i].size() * words[j].size();
                for(int k = 0; k < 25; k++)
                {
                    if(store[i][k] and store[j][k])
                    {
                        isCommotWord = true;
                        break;
                    }
                }
                if(not isCommotWord) ans = max(ans, mul);
            }
        }
        return ans;    
    }
};