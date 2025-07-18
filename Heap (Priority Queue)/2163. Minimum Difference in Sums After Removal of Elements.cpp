class Solution {
public:
    long long minimumDifference(vector<int>& nums) 
    {
        int n = nums.size(), k = n / 3;

        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;

        long long sum = 0;
        vector<long long> leftSum(n), rightSum(n);
        for(int i = 0; i < n - k; i++)
        {
            sum += nums[i];
            maxHeap.push(nums[i]);
            if(maxHeap.size() > k) 
            {
                sum -= maxHeap.top();
                maxHeap.pop();
            }
            leftSum[i] = sum;
        }

        sum = 0;
        for(int i = n - 1; i >= k; i--)
        {
            sum += nums[i];
            minHeap.push(nums[i]);
            if(minHeap.size() > k) 
            {
                sum -= minHeap.top();
                minHeap.pop();
            }
            rightSum[i] = sum;
        }

        long long ans = 2e18;
        for(int i = k - 1; i < n - k; i++)
            ans = min(ans, leftSum[i] - rightSum[i + 1]);
        return ans;
    }
};