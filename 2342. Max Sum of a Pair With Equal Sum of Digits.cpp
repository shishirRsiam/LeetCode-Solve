class Solution {
public:
    int maximumSum(vector<int>& nums) 
    {
        string s;
        long sum, ans = 0;
        unordered_map<int, priority_queue<int>>store;
        for(auto val:nums)
        {
            sum = 0;
            s = to_string(val);
            for(auto ch:s) sum += ch - '0';
            store[sum].push(val);
        }

        for(auto [sumCount, pq]:store)
        {
            if(pq.size() == 1) continue;
            sum = pq.top(); pq.pop();
            sum += pq.top();
            ans = max(ans, sum);
        }
        return ans ? ans : -1;
    }
};