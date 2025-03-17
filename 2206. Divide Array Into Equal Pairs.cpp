class Solution {
    public:
        bool divideArray(vector<int>& nums) 
        {
            unordered_map<int, int> store;
            for(auto &val : nums) store[val] += 1;
            for(auto [val, count] : store)
                if(count % 2) return false;
            return true;    
        }
    };