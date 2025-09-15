class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) 
    {
        unordered_map<int, int> countOrder;
        for(const int &f : friends)
            countOrder[f] += 1;
        
        vector<int> ans;
        for(const int &o : order)
        {
            if(countOrder[o])
            {
                ans.push_back(o);
                countOrder[o]--;
            }
        }
        return ans;
    }
};