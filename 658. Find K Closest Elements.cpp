class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
        multiset<int>ml;
        for(auto val:arr) ml.insert(val);
        
        vector<int>ans;
        int val1, val2;
        while(k--)
        {
            auto it = ml.upper_bound(x);

            if(it == ml.end()) val1 = INT_MAX;
            else val1 = *it;

            auto it2 = it;
            if(it2 != ml.begin()) it2--;
            val2 = *it2;
            
            if(abs(val1 - x) < abs(val2 - x))
            {
                ans.push_back(val1);
                ml.erase(it);
            }
            else 
            {
                ans.push_back(val2);
                ml.erase(it2);
            }
        }
        sort(begin(ans), end(ans));
        return ans;
    }
};