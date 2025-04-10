class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) 
    {
        vector<string> ans;
        for(auto &querie : queries)
        {
            for(auto &dict : dictionary)
            {
                if(querie.size() != dict.size()) continue;
                
                int changeCount = 0, n = dict.size();
                for(int i = 0; i < n; i++)
                {
                    if(dict[i] != querie[i])
                    {
                        changeCount += 1;
                        if(changeCount > 2) break;
                    }
                }
                if(changeCount <= 2)
                {
                    ans.push_back(querie);
                    break;
                }
            }
        }
        return ans;
    }
};