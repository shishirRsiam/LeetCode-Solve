class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& a) 
    {
        sort(a.begin(), a.end());

        int n = a.size();
        int minABS = INT_MAX;
        for(int i = 1; i < n; i++)
        {
            if(minABS > abs(a[i - 1] - a[i])) 
                minABS = abs(a[i - 1] - a[i]);
        }

        vector<vector<int>> ans;
        for(int i = 1; i < n; i++)
        {
            if(abs(a[i - 1] - a[i]) == minABS) 
                ans.push_back({a[i - 1], a[i]});
        }
        return ans;
    }
};