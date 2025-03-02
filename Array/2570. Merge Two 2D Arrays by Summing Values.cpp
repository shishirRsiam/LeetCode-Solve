class Solution {
    public:
        vector<vector<int>> mergeArrays(vector<vector<int>>& a, vector<vector<int>>& b) 
        {
            map<int,int>mp;
            for(auto x:a) mp[x[0]] += x[1];
            for(auto x:b) mp[x[0]] += x[1];
    
            vector<vector<int>> ans;
            for(auto x:mp) ans.push_back({x.first,x.second});
            return ans;
        }
    };