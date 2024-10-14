class Solution
{
public:
    long long maxKelements(vector<int> &nums, int k)
    {
        long ans = 0, val;
        priority_queue<int> pq;
        for (auto val : nums)
            pq.push(val);
        while (k--)
        {
            val = pq.top();
            pq.pop();
            ans += val;
            pq.push(ceil(val / 3.0));
        }
        return ans;
    }
};