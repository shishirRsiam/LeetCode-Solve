class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) 
    {
        vector<int> needValue;
        int ans = 0, n = rocks.size();
        for(int i=0;i<n;i++)
            needValue.push_back(capacity[i] - rocks[i]);
            
        sort(begin(needValue), end(needValue));
        for(auto val:needValue)
        {
            additionalRocks -= val;
            if(additionalRocks < 0) break;
            ans += 1;
        }
        return ans;
    }
};