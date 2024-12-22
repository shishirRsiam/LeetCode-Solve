#define pi pair<int, int>
class Solution {
public:
    vector<pi> store;
    int getIndex(int num, int idx)
    {
        int index = INT_MAX;
        for(auto [val, i] : store) {
            if(val <= num) break;
            if(i >= idx) index = min(index, i);
        }
        return index == INT_MAX ? -1 : index;
    }
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) 
    {
        int n = heights.size();
        for(int i = 1; i < n; i++)
            if(heights[i - 1] < heights[i]) store.push_back({heights[i], i});
        sort(rbegin(store), rend(store));

        n = queries.size();
        vector<int> ans(n);
        for(int i = 0; i < n; i++)
        {
            int aliceIdx = queries[i][0], bobIdx = queries[i][1];
            if(aliceIdx == bobIdx) ans[i] = aliceIdx;
            else {
                int aliceVal = heights[aliceIdx], bobVal = heights[bobIdx];
                int searchIdx = max(aliceIdx, bobIdx), searchVal = max(aliceVal, bobVal);

                if(aliceIdx > bobIdx and aliceVal > bobVal) ans[i] = searchIdx;
                else if(bobIdx > aliceIdx and bobVal > aliceVal) ans[i] = searchIdx;
                else ans[i] = getIndex(searchVal, searchIdx);
            }
        }
        return ans;  
    }
};