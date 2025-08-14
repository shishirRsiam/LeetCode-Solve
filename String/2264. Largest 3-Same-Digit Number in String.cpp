class Solution {
public:
    string largestGoodInteger(string num)
    {
        bool flag = true;
        string ans = "000";
        int n = num.size() - 2;
        for (int i = 0; i < n; i++)
        {
            if (num[i] == num[i + 1] and num[i] == num[i + 2])
            {
                flag = false;
                ans = max(ans, num.substr(i, 3));
            }
        }
        return flag ? "" : ans;
    }
};