#define tuple tuple<int, int>
class Solution {
public:
    int minDeletion(string s, int k) 
    {
        unordered_map<int, int> count;
        for(auto &ch : s) count[ch] += 1;
        
        priority_queue<tuple, vector<tuple>, greater<tuple>> minHeap;
        for(auto [ch, cnt] : count)
            minHeap.push({cnt, ch});
        
        int ans = 0;
        while(minHeap.size() > k)
        {
            auto [cnt, ch] = minHeap.top(); minHeap.pop();
            ans += cnt;
        }
        return ans;   
    }
};