class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) 
    {
        priority_queue<int, vector<int>, greater<int>>minHeap;
        for(auto val:nums) minHeap.push(val);

        while(k--)
        {
            int val = minHeap.top();
            minHeap.pop();
            minHeap.push(-val);
        }

        int maxSum = 0;
        while(!minHeap.empty())
        {
            maxSum += minHeap.top();
            minHeap.pop();
        }
        return maxSum;
    }
};