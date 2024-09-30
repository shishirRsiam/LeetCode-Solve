class Solution
{
public:
    int duplicateNumbersXOR(vector<int> &nums)
    {
        vector<int> store, count(100);
        for (auto val : nums)
        {
            count[val]++;
            if (count[val] == 2)
                store.push_back(val);
        }
        int ans = 0;
        for (auto val : store)
            ans ^= val;
        return ans;
    }
};