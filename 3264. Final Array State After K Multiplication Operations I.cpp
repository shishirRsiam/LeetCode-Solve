typedef pair<long, int> pi;
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) 
    {
        priority_queue<pi, vector<pi>, greater<pi>>minHeap;
        
        int n = nums.size();
        for(int i=0;i<n;i++)
            minHeap.push({nums[i], i});
        
        while(k--)
        {
            auto [val, idx] = minHeap.top(); minHeap.pop();
            minHeap.push({val * multiplier, idx});
        }

        vector<int>ans(n);
        while(!minHeap.empty())
        {
            auto [val, idx] = minHeap.top(); minHeap.pop();
            ans[idx] = val;
        }
        return ans;
    }
};