// 12 Nov 2024 : 2070. Most Beautiful Item for Each Query
class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) 
    {
        map<int, int>store;
        for(auto vec:items)
            store[vec[0]] = max(store[vec[0]], vec[1]);
        
        store[0] = 0;
        store[INT_MAX] = store.rbegin()->second;

        int mxBeauty = 0;
        for(auto [price, beauty] : store)
        {
            mxBeauty = max(mxBeauty, beauty);
            store[price] = mxBeauty;
        }

        vector<int>ans;
        for(auto price : queries)
        {
            auto it = store.lower_bound(price);
            if(it->first > price) it--;
            ans.push_back(it->second);
        }
        return ans;
    }
};