class Solution
{
public:
    static bool cmp(int a, int b)
    {
        return to_string(a) + to_string(b) > to_string(b) + to_string(a);
    }
    string largestNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), cmp);

        if (nums[0] == 0)
            return "0";

        string ans;
        for (int n : nums)
            ans += to_string(n);

        return ans;
    }
};

class Solution
{
public:
    class cmp
    {
    public:
        bool operator()(string &a, string &b)
        {
            return a + b < b + a;
        }
    };
    string largestNumber(vector<int> &nums)
    {
        priority_queue<string, vector<string>, cmp> pq;
        for (auto val : nums)
        {
            string s = to_string(val);
            pq.push(s);
        }

        string ans;
        while (!pq.empty())
        {
            ans += pq.top();
            pq.pop();
        }
        return ans[0] == '0' ? "0" : ans;
    }
};