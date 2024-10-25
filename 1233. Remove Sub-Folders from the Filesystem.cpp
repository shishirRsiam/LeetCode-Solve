class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) 
    {
        sort(begin(folder), end(folder));
        vector<string>ans(1);
        ans[0] = folder[0];

        int n = folder.size();
        for(int i = 1; i < n; i++)
        {
            auto target = ans.back();
            auto s = folder[i].substr(0, target.size());
            if(target != s or folder[i][target.size()] != '/')
                ans.push_back(folder[i]);
        }  
        return ans;  
    }
};