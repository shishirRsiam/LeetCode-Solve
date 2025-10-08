class Solution {
public:
    auto binarySearchForPosition(long long min_target, int pos, vector<int>& potions)
    {
        int i = 0, j = pos - 1, mid;
        while(i <= j)
        {
            mid = i + (j - i) / 2;
            if(potions[mid] >= min_target) pos = mid, j = mid - 1;
            else i = mid + 1;
        }
        return pos;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) 
    {
        vector<int> ans;
        sort(potions.begin(), potions.end());
        int n = spells.size(), m = potions.size();
        for(auto &val : spells)
        {
            long long min_target = ceil(success / double(val));
            auto pos = binarySearchForPosition(min_target, m, potions);
            ans.push_back(m - pos);
        }
        return ans;
    }
};