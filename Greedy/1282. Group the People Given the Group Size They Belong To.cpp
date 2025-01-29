class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) 
    {
        int n = groupSizes.size();
        map<int, vector<int>> store;
        for(int i = 0; i < n; i++)
            store[groupSizes[i]].push_back(i);

        vector<vector<int>> ans;
        for(auto [i, idx] : store)
        {
            vector<int> group;
            for(auto j : idx)
            {
                group.push_back(j);
                if(group.size() == i)
                {
                    ans.push_back(group);
                    group.clear();
                }
            }
        }

        return ans;
    }
};