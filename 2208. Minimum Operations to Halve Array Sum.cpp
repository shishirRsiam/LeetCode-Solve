class Solution
{
public:
    int halveArray(vector<int> &nums)
    {
        double target = 0;
        priority_queue<double> pq;
        for (auto val : nums)
        {
            target += (val / 2.0);
            pq.push(val);
        }

        int ans = 0;
        while (target > 0)
        {
            ans += 1;
            target -= (pq.top() / 2.0);
            pq.push(pq.top() / 2.0);
            pq.pop();
        }
        return ans;
    }
};