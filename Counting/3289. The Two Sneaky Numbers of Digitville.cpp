class Solution
{
public:
    vector<int> getSneakyNumbers(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans, count(n);
        for (auto val : nums)
        {
            count[val]++;
            if (count[val] == 2)
                ans.push_back(val);
        }
        return ans;
    }
};