class Solution {
public:
    vector<string> divideString(string s, int k, char fill) 
    {
        while(s.size() % k) 
            s += fill;

        int n = s.size();
        vector<string> ans;
        for(int i = 0; i < n; i += k)
            ans.push_back(s.substr(i, k));
        return ans;     
    }
};