class Solution {
    public:
        int minOperations(vector<int> &nums, int k)
        {
            priority_queue<long, vector<long>, greater<long>> minHeap;
            for (int &val : nums) minHeap.push(val);
    
            int ans = 0;
            while (minHeap.size() > 1 and k > minHeap.top())
            {            
                ans += 1;
                long minVal = minHeap.top(); minHeap.pop();
                long maxVal = minHeap.top(); minHeap.pop();
                minHeap.push(minVal * 2 + maxVal);
            }
            return ans;
        }
    };