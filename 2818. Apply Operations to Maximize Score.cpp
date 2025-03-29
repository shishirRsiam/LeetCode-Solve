class Solution
{
public:
    int mod = 1e9 + 7;
    long pow(long base, long exp, int mod)
    {
        long res = 1;
        while (exp)
        {
            if (exp % 2) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }
    auto nextGreaterElement(vector<int> &nums)
    {
        stack<int> st;
        int n = nums.size();
        vector<int> ans(n, n);
        for (int i = 0; i < n; i++)
        {
            while (st.size() and nums[st.top()] < nums[i])
            {
                ans[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
    auto prevGreaterElement(vector<int> &nums)
    {
        stack<int> st;
        int n = nums.size();
        vector<int> ans(n, n);
        for (int i = 0; i < n; i++)
        {
            while (st.size() and nums[i] > nums[st.top()])
                st.pop();
            ans[i] = st.size() ? st.top() : -1;
            st.push(i);
        }
        return ans;
    }
    int maximumScore(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> prime_score;
        priority_queue<pair<int, int>> maxHeap;
        for (int i = 0; i < n; i++)
        {
            int score = 0, val = nums[i];
            for (int i = 2; i <= sqrt(val); i++)
            {
                score += val % i == 0;
                while (val % i == 0)
                    val /= i;
            }

            if (val > 1)
                score += 1;
            maxHeap.push({nums[i], i});
            prime_score.push_back(score);
        }
        auto prevGreater = prevGreaterElement(prime_score);
        auto nextGreater = nextGreaterElement(prime_score);

        long ans = 1;
        while (!maxHeap.empty())
        {
            auto [val, index] = maxHeap.top();
            maxHeap.pop();

            long left_range = index - prevGreater[index];
            long right_range = nextGreater[index] - index;
            long contribution = left_range * right_range;

            long take = min((long)k, contribution);
            ans = (ans * pow(val, take, mod)) % mod;

            k -= take;
        }
        return ans;
    }
};