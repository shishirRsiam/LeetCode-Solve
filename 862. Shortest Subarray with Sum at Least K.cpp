class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) 
    {
        int n = nums.size(), j = 0, ans = INT_MAX;
        vector<long>CumulativeSum(n, 0);

        deque<int> deq;
        while(j < n)
        {
            if(j == 0) CumulativeSum[j] = nums[j];
            else CumulativeSum[j] = CumulativeSum[j - 1] + nums[j];

            if(CumulativeSum[j] >= k)
                ans = min(ans, j + 1);

            while(!deq.empty() and CumulativeSum[j] - CumulativeSum[deq.front()] >= k)
            {
                ans = min(ans, j - deq.front());
                deq.pop_front();
            }
            while(!deq.empty() and CumulativeSum[j] <= CumulativeSum[deq.back()])
            {
                deq.pop_back();
            }

            deq.push_back(j);
            j++;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};