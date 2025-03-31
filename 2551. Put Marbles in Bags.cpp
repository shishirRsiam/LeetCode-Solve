class Solution {
    public:
        long long putMarbles(vector<int>& weights, int k) 
        {
            k -= 1;
            priority_queue<long> maxHeap;
            long minScore = 0, maxScore = 0, n = weights.size();
            priority_queue<long, vector<long>, greater<long>> minHeap;
    
            for(int i = 0; i < n - 1; i++)
            {
                minHeap.push(weights[i] + weights[i + 1]);
                maxHeap.push(weights[i] + weights[i + 1]);
            }
            while(k--)
            {
                minScore += minHeap.top(); minHeap.pop();
                maxScore += maxHeap.top(); maxHeap.pop();
            }
            return maxScore - minScore;
        }
    };