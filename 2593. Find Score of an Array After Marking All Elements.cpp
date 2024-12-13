#define pi pair<int, int> 
class Solution {
public:
    long long findScore(vector<int>& nums) 
    {
        int n = nums.size();
        priority_queue<pi, vector<pi>, greater<pi>> minHeap;
        for(int i = 0; i < n; i++)
            minHeap.push({nums[i], i});

        long ans = 0;
        unordered_map<int, bool> visited;
        while(!minHeap.empty())
        {
            auto [value, idx] = minHeap.top(); minHeap.pop();
            if(visited[idx]) continue;

            ans += value;
            visited[idx + 1] = true;
            visited[idx - 1] = true;
        }

        return ans;   
    }
};