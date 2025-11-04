class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) 
    {
        vector<int> ans;
        int n = nums.size();
        for(int i = 0; i <= n - k; i++)
        {
            int mx = 0, temp = x, sum = 0;
            unordered_map<int, int> count;
            for(int j = i; j < i + k; j++)
                count[nums[j]] += 1;

            priority_queue<pair<int, int>> maxHeap;
            for(auto &[val, cnt] : count)
                maxHeap.push({cnt, val});
            while(not maxHeap.empty() and temp--)
            {
                auto [cnt, val] = maxHeap.top(); maxHeap.pop();
                sum += (val * cnt);
            }
            ans.push_back(sum);
        }
        return ans;
    }
};