class Solution
{
public:
    long long pickGifts(vector<int> &gifts, int k)
    {
        priority_queue<int> pq;
        for (auto val : gifts)
            pq.push(val);

        while (k--)
        {
            pq.push(sqrt(pq.top()));
            pq.pop();
        }

        long ans = 0;
        while (!pq.empty())
        {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};