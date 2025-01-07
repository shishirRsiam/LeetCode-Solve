class Solution {
public:
    vector<string> stringMatching(vector<string>& w) 
    {
        sort(w.begin(),w.end());
        int n = w.size();
        set<string>tmp;
        for(int i=0;i<n;i++)
        {
            for(auto x:w)
            {
                if(w[i] != x)
                {
                    auto it = x.find(w[i]);
                    if(it <= x.size()) tmp.insert(w[i]);
                }
            }
        }
        vector<string>ans(vector<string>(tmp.begin(),tmp.end()));
        return ans;
    }
};