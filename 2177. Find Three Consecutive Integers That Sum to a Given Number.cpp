class Solution
{
public:
    vector<long long> sumOfThree(long long num)
    {
        if (not(num % 3))
        {
            long long mod = num / 3;
            return {mod - 1, mod, mod + 1};
        }
        return {};
    }
};

class Solution
{
public:
    vector<long long> sumOfThree(long long num)
    {
        vector<long long> ans;
        if (not(num % 3))
        {
            long long mod = num / 3;
            ans.push_back(mod - 1);
            ans.push_back(mod);
            ans.push_back(mod + 1);
        }
        return ans;
    }
};